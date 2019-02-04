cmake_minimum_required(VERSION 2.8)

project(helloworld)

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:\\Program Files\\boost\\include\\boost-1_66")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:\\Program Files\\boost\\lib")

FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    #ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

add_executable(helloworld main.cpp)

target_link_libraries(helloworld "C:/Program Files/boost/lib/libboost_chrono-mgw82-mt-x64-1_66.a" "C:/Program Files/boost/lib/libboost_system-mgw82-mt-x64-1_66.a")
