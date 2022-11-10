from serial import Serial
from time import sleep
from math import atan,pi,floor
from enum import Enum

name = "PyLidar2"

class FrequencyStep(Enum):
    oneTenthHertz=1
    oneHertz=2

class YdLidarX4:
    """Deals with X4 version of Ydlidar from http://www.ydlidar.com/"""
    def __init__(self,port,chunk_size=6000):
        """Initialize the connection and set port and baudrate."""
        self._port = port
        self._baudrate = 128000
        self._is_scanning = False
        self._is_connected = False
        self.chunk_size=chunk_size
        
    def Connect(self):
        """Begin serial connection with Lidar by opening serial port.\nReturn success status True/False.\n"""
        try:
            if(not self._is_connected):
                self._s=Serial(self._port, self._baudrate)
                self._is_connected = True
                sleep(3)
                self._s.reset_input_buffer()
                if("YdLidarX4" in str(type(self))):
                    self._Stop_motor()
                if(self.GetHealthStatus()):
                    return True
                else:
                    raise Exception('Device health status error.Try reconnecting device')
            else:
                raise Exception("Already connected")
        except Exception as e:
            print(e)
            return False
        
    def _Start_motor(self):
        self._s.setDTR(1)
        sleep(0.5)
        
    def _Stop_motor(self):
        self._s.setDTR(0)
        sleep(0.5)
            
    @classmethod    
    def _AngleCorr(cls,dist):
        if dist==0:
            return 0
        else:
            return (atan(21.8*((155.3-dist)/(155.3*dist)))*(180/pi))
    @classmethod  
    def _HexArrToDec(cls,data):
        littleEndianVal = 0
        for i in range(0,len(data)):
            littleEndianVal = littleEndianVal+(ord(data[i])*(256**i))
        return littleEndianVal
    
    @classmethod
    def _Calculate(cls,d):
        ddict=[]
        LSN=ord(d[1])
        Angle_fsa = ((YdLidarX4._HexArrToDec((d[2],d[3]))>>1)/64.0)+YdLidarX4._AngleCorr(YdLidarX4._HexArrToDec((d[8],d[9]))/4)
        Angle_lsa = ((YdLidarX4._HexArrToDec((d[4],d[5]))>>1)/64.0)+YdLidarX4._AngleCorr(YdLidarX4._HexArrToDec((d[LSN+6],d[LSN+7]))/4)
        if Angle_fsa<Angle_lsa:
            Angle_diff = Angle_lsa-Angle_fsa
        else:
            Angle_diff = 360+Angle_lsa-Angle_fsa
        for i in range(0,2*LSN,2):
            dist_i = YdLidarX4._HexArrToDec((d[8+i],d[8+i+1]))/4
            Angle_i_tmp = ((Angle_diff/float(LSN))*(i/2))+Angle_fsa+YdLidarX4._AngleCorr(dist_i)
            if Angle_i_tmp > 360:
                Angle_i = Angle_i_tmp-360
            elif Angle_i_tmp < 0:
                Angle_i = Angle_i_tmp+360
            else:
                Angle_i = Angle_i_tmp
            ddict.append((dist_i,Angle_i))
        return ddict
    
    @classmethod
    def _CheckSum(cls,data):
        try:
            ocs = YdLidarX4._HexArrToDec((data[6],data[7]))
            LSN = ord(data[1])
            cs = 0x55AA^YdLidarX4._HexArrToDec((data[0],data[1]))^YdLidarX4._HexArrToDec((data[2],data[3]))^YdLidarX4._HexArrToDec((data[4],data[5]))
            for i in range(0,2*LSN,2):
                cs = cs^YdLidarX4._HexArrToDec((data[8+i],data[8+i+1])) 
            if(cs==ocs):
                return True
            else:
                return False
        except Exception as e:
            return False
        
    @classmethod
    def _Mean(cls,data):
        if(len(data)>0):
            return int(sum(data)/len(data))
        return 0
    
    def StartScanning(self):
        """Begin the lidar and returns a generator which returns a dictionary consisting angle(degrees) and distance(meters).\nReturn Format : {angle(1):distance, angle(2):distance,....................,angle(360):distance}."""
        if(self._is_connected):
            if(not self._is_scanning):
                self._is_scanning = True
                self._s.reset_input_buffer()
                if("YdLidarX4" in str(type(self))):
                    self._Start_motor()
                self._s.write(chr(0xA5)+chr(0x60))
                sleep(0.5)
                self._s.read(7)
                distdict = {}
                countdict = {}
                while self._is_scanning == True:
                    for i in range(0,360):
                        distdict.update({i:[]})
                    data = self._s.read(self.chunk_size).split("\xaa\x55")[1:-1]
                    for e in data:
                        try:
                            if(ord(e[0])==0):
                                if(YdLidarX4._CheckSum(e)):
                                    d = YdLidarX4._Calculate(e)
                                    for ele in d:
                                        angle = floor(ele[1])
                                        if(angle>=0 and angle<360):
                                            distdict[angle].append(ele[0])
                        except Exception as e:
                            pass
                    for i in distdict.keys():
                        distdict[i]=self._Mean(distdict[i])
                    yield distdict  
            else:
                raise Exception("Device is currently in scanning mode.")
        else:
            raise Exception("Device is not connected")    
            
    def StopScanning(self):
        """Stops scanning but keeps serial connection alive."""
        if(self._is_connected):
            if(self._is_scanning):
                self._is_scanning = False
                self._s.write(chr(0xA5)+chr(0x65))
                sleep(1)
                self._s.reset_input_buffer()
                if("YdLidarX4" in str(type(self))):
                    self._Stop_motor()
            else:
                raise Exception("Device is not set to scanning mode")
        else:
            raise Exception("Device is not connected")


    def GetHealthStatus(self):
        """Returns Health status of lidar\nTrue: good\nFalse: Not good"""
        if(self._is_connected):
            if self._is_scanning == True:
                self.StopScanning()
            self._s.reset_input_buffer()
            sleep(0.5)
            self._s.write(chr(0xA5)+chr(0x91))
            sleep(0.5)
            data = self._s.read(10)
            if ord(data[9])==0 and ord(data[8])==0 and (ord(data[7])==0 or ord(data[7])==1):
                return True
            else:
                return False
        else:
            raise Exception("Device is not connected")
        
    def GetDeviceInfo(self):
        """Return device information of lidar in form of dictonary\n{"model_number":model_number,"firmware_version":firmware_version,"hardware_version":hardware_version,"serial_number":serial_number}"""
        if(self._is_connected):
            if self._is_scanning == True:
                self.StopScanning()
            self._s.reset_input_buffer()
            sleep(0.5)
            self._s.write(chr(0xA5)+chr(0x90))
            sleep(0.5)
            data = self._s.read(27)
            model_number = str(ord(data[7]))
            firmware_version = str(ord(data[9]))+"."+str(ord(data[8]))
            hardware_version = str(ord(data[10]))
            serial_number = ""
            for i in range(11,20):
                serial_number = serial_number+str(ord(data[i]))
            return {"model_number":model_number,"firmware_version":firmware_version,"hardware_version":hardware_version,"serial_number":serial_number}
        else:
            raise Exception("Device is not connected")
        
    def Reset(self):
        """Reboots the Lidar."""
        if(self._is_connected):
            self._s.write(chr(0xA5)+chr(0x40))
            sleep(0.5)
            self.Disconnect()
            self.Connect()
        else:
            raise Exception("Device is not connected")
        
    def Disconnect(self):
        """Stop scanning and close serial communication with Lidar."""
        if(self._is_connected):
            if(self._is_scanning == True):
                self.StopScanning()
            self._s.close()
            self._is_connected=False
        else:
            raise Exception("Device is not connected")
    
class YdLidarG4(YdLidarX4):
    """Deals with G4 version of Ydlidar from http://www.ydlidar.com/"""
    def __init__(self,port,chunk_size=6000):
        """Initialize the connection and set port and baudrate."""
        YdLidarX4.__init__(self,port,chunk_size)
        self._baudrate= 230400
        
    def EnableLowPowerMode(self):
        """Enable Low Power Consumption Mode(Turn motor and distance-measuring unit off in StopScanning)\n"""
        if(self._is_connected):
            if self._is_scanning == True:
                self.StopScanning()
            self._s.write(chr(0xA5)+chr(0x01))
            while(self._s.inWaiting()==0):
                sleep(0.5)
            self._s.reset_input_buffer()
        else:
            raise Exception("Device is not connected")
        
    def DisableLowPowerMode(self):
        """Disable Low Power Consumption Mode(Turn motor and distance-measuring unit on StopScanning)\n"""
        if(self._is_connected):
            if self._is_scanning == True:
                self.StopScanning()
            self._s.write(chr(0xA5)+chr(0x02))
            while(self._s.inWaiting()==0):
                sleep(0.5)
            self._s.reset_input_buffer()
        else:
            raise Exception("Device is not connected")

    def GetLowPowerModeStatus(self):
        """Return True if Low Power Consumption Mode is Enable else return False"""
        if(self._is_connected):
            if self._is_scanning == True:
                self.StopScanning()
            self._s.reset_input_buffer()
            sleep(0.5)
            self._s.write(chr(0xA5)+chr(0x05))
            sleep(1)
            data = self._s.read(8)
            if(ord(data[7])!=1):
                return True
            return False
        else:
            raise Exception("Device is not connected")
    
    def IncreaseCurrentFrequency(self,frequencyStep):
        """Increase current frequency by oneTenth or one depends on enum FrequencyStep"""
        if(self._is_connected):
            if self._is_scanning == True:
                self.StopScanning()
            if(frequencyStep==1):
                self._s.write(chr(0xA5)+chr(0x09))
            elif(frequencyStep==2):
                self._s.write(chr(0xA5)+chr(0x0B))
            while(self._s.inWaiting()==0):
                sleep(0.5)
            self._s.reset_input_buffer()
        else:
            raise Exception("Device is not connected")
    
    def DecreaseCurrentFrequency(self,frequencyStep):
        """Decrease current frequency by oneTenth or one depends on enum FrequencyStep"""
        if(self._is_connected):
            if self._is_scanning == True:
                self.StopScanning()
            if(frequencyStep==1):
                self._s.write(chr(0xA5)+chr(0x0A))
            elif(frequencyStep==2):
                self._s.write(chr(0xA5)+chr(0x0C))
            while(self._s.inWaiting()==0):
                sleep(0.5)
            self._s.reset_input_buffer()
        else:
            raise Exception("Device is not connected")
    
    def GetCurrentFrequency(self):
        """Returns current frequency in hertz"""
        if(self._is_connected):
            if self._is_scanning == True:
                self.StopScanning()
            self._s.reset_input_buffer()
            sleep(0.5)
            self._s.write(chr(0xA5)+chr(0x0D))
            sleep(0.5)
            data = self._s.read(11)
            if(ord(data[0])==165):
                return (self._HexArrToDec(data[-4:]))/100.0
            else:
                return (self._HexArrToDec(data[:4]))/100.0
        else:
            raise Exception("Device is not connected")
        
    def EnableConstantFrequency(self):
        """Enables constant frequency \n default:Enable"""
        if(self._is_connected):
            if self._is_scanning == True:
                self.StopScanning()
            self._s.write(chr(0xA5)+chr(0x0E))
            while(self._s.inWaiting()==0):
                sleep(0.5)
            self._s.reset_input_buffer()
        else:
            raise Exception("Device is not connected")
    
    def DisableConstantFrequency(self):
        """Disable constant frequency \n default:Enable"""
        if(self._is_connected):
            if self._is_scanning == True:
                self.StopScanning()
            self._s.write(chr(0xA5)+chr(0x0F))
            while(self._s.inWaiting()==0):
                sleep(0.5)
            self._s.reset_input_buffer()
        else:
            raise Exception("Device is not connected")
    
    def SwitchRangingFrequency(self):
        """Switch between ranging frequencies 4khz, 8khz and 9khz.\ndefault:9khz"""
        if(self._is_connected):
            if self._is_scanning == True:
                self.StopScanning()
            self._s.write(chr(0xA5)+chr(0xD0))
            while(self._s.inWaiting()==0):
                sleep(0.5)
            self._s.reset_input_buffer()
        else:
            raise Exception("Device is not connected")
    
    def GetCurrentRangingFrequency(self):
        """Returns current Ranging Frequency in khz"""
        if(self._is_connected):
            if self._is_scanning == True:
                self.StopScanning()
            self._s.reset_input_buffer()
            sleep(0.5)
            self._s.write(chr(0xA5)+chr(0xD1))
            sleep(1)
            data = self._s.read(8)
            if(ord(data[-1])==0):
                return 4
            elif(ord(data[-1])==1):
                return 8
            elif(ord(data[-1])==2):
                return 9
        else:
            raise Exception("Device is not connected")
        
    def Disconnect(self):
        """Stop scanning and close serial communication with Lidar."""
        if(self._is_connected):
            if(self._is_scanning == True):
                self.StopScanning()
            if(self.GetLowPowerModeStatus()==False):
                self.EnableLowPowerMode()
                sleep(2)
            self._s.close()
            self._is_connected=False
        else:
            raise Exception("Device is not connected")
