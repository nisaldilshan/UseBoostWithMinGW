# UseBoostWithMinGW

This project shows how to use Boost libraries for your c++ projects and build for MinGW with cmake

## Getting Started

First you need to build boost libraries targeting MinGW, for that you can find instructions here.
  https://gist.github.com/sim642/29caef3cc8afaa273ce6
  
OR

Can download boost libs directly using "pacboy"
  https://github.com/boostorg/stacktrace/issues/14


### Installing

After that you need to create a CMakeLists.txt file and append boost include path and library path to "CMAKE_INCLUDE_PATH" and "CMAKE_LIBRARY_PATH".

Then you can call "FIND_PACKAGE(Boost)" , if this failed please check above path variables or rebuild boost with matching configurations.

Then you need to Add "${Boost_INCLUDE_DIR}" to include_directories of this project and after that you can add your executable.

Finally you need to link your executables with relavant boost libraries (boost_system is needed for most of the other boost libs, threfore you need add that as well).

Refer to attached CMakeLists.txt file which links boost_chrono library with the target executable.

## Deployment

its better to have a separate build folder
```
mkdir build
```

Run Following commands to Generate CMake Project

```
cd build
cmake .. -G "MinGW Makefiles"
```

Run following command to build your project
```
cmake --build .. 
```
or 
```
mingw32-make
```

