#!/usr/bin/env python3


def convert_serial_number_for_16_ticks(config_file_path="/home/pi/Dexter/gpg3_config.json"):
        '''
        Check known list of serial numbers that were shipped with 16 tick motors
        '''
        import pickle
        from os import path
        serial_path = path.split(config_file_path)[0]
        serial_file = serial_path+"/.list_of_serial_numbers.pkl"
        try:
            with open(serial_file, 'rb') as f:
                serials_with_16_ticks = pickle.load(f)
                with open(".list_of_serial_numbers.txt", "wt") as sf:
                    for serial in serials_with_16_ticks:
                        sf.write(serial+'\n')
            print(".list_of_serials_with_16_ticks.txt written - note dotName")
        except:
            print("file not found")



if (__name__ == "__main__") :
  convert_serial_number_for_16_ticks()
