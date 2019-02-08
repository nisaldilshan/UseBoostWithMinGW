cmake_minimum_required(VERSION 2.8)

project(boost-helloworld)

#SET (CMAKE_CXX_FLAGS_INIT "-Wall -Wextra -std=gnu++2a -fcoroutines-ts -stdlib=libc++-dev")

SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:\\Program Files\\boost\\include\\boost-1_66")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:\\Program Files\\boost\\lib")

FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    #ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

IF(${CMAKE_CXX_COMPILER} STREQUAL "C:/msys64/mingw64/bin/clang++.exe")
    message(${CMAKE_CXX_COMPILER})
    add_executable(coroutineTS coroutineTS.cpp)
ELSE()
    add_executable(chrono chrono.cpp)
    add_executable(coroutine2 coroutines.cpp)
    add_executable(asiocoroutine asioCoroutines.cpp)

    target_link_libraries(chrono 
    "C:/Program Files/boost/lib/libboost_chrono-mgw82-mt-x64-1_66.a" 
    "C:/Program Files/boost/lib/libboost_system-mgw82-mt-x64-1_66.a"
    )

    target_link_libraries(coroutine2 
    "C:/Program Files/boost/lib/libboost_coroutine-mgw82-mt-x64-1_66.a" 
    "C:/Program Files/boost/lib/libboost_context-mgw82-mt-x64-1_66.a"
    )

    target_link_libraries(asiocoroutine 
    "C:/Program Files/boost/lib/libboost_coroutine-mgw82-mt-x64-1_66.a"
    )
ENDIF()




