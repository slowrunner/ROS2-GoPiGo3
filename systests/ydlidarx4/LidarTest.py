import PyLidar2
import time # Time module
#Serial port to which lidar connected, Get it from device manager windows
#In linux type in terminal -- ls /dev/tty* 
port = raw_input("Enter port name which lidar is connected:") #windows
#port = "/dev/ttyUSB0" #linux
Obj = PyLidar2.YdLidarX4(port)
if(Obj.Connect()):
    print(Obj.GetDeviceInfo())
    gen = Obj.StartScanning()
    t = time.time() # start time 
    while (time.time() - t) < 30: #scan for 30 seconds
        print(gen.next())
        time.sleep(0.5)
    Obj.StopScanning()
    Obj.Disconnect()
else:
    print("Error connecting to device")
