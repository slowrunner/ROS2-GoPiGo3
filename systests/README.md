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
