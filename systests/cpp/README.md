# Programming GoPiGo3 in C++ (Using GoPiGo3.cpp)

# Directory Structure
```
../cpp_workspace/  
    CMakeLists.txt
    package.xml
    GoPiGo3.cpp
    GoPiGo3.h
    gopigo3_cppConfig.cmake.in

../cpp_workspace/src/
    my_program.cpp  
```

# New Program:  my_program.cpp
1) create ../cpp_workspace/src/my_program.cpp
2) edit CMMakeLists.txt
```
add:

# my_program
add_executable(my_program src/my_program.cpp)
target_link_libraries(my_program gopigo3)
```

3) cmake CMakeLists.txt
4) make
5) ./my_program


# systests/cpp
Examples:
- info returns GoPiGo3 board values:
```
GoPiGo3 info:
  Manufacturer    : Dexter Industries
  Board           : GoPiGo3
  Serial Number   : 56ECD67E5152415447202020FF192614
  Hardware version: 3.x.x
  Firmware version: 1.0.0
  Battery voltage : 9.234
  5v voltage      : 4.967

```
- leds cycles the "Eyes" and "Blinkers"
- "motors" I renamed to "encoders" as it actually only returns left and right encoder values
- us_ranger:   reads the Grove Ultrasonic Ranger in AD2
- drive:  allows key press (a w d x) driving of GoPiGo3

To build:
1) cd ~/systests/cpp
2) cmake CMakeLists.txt
3) make
4) ./drive  or ./info  or ./leds  or  ./encoders  or  ./us_ranger
