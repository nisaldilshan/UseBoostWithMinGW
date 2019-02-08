cmake_minimum_required(VERSION 2.8)

project(boost-helloworld)

# SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
# SET(GCC_COVERAGE_LINK_FLAGS    "-lboost_fiber -lboost_context")

#-DBOOST_STACKTRACE_USE_WINDBG
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DBOOST_STACKTRACE_USE_BACKTRACE -IC:\\dev\\stacktrace\\include")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -LC:\\msys64\\mingw64\\lib")

#SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:\\dev\\stacktrace\\include")
#SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:\\Program Files\\boost\\lib")

FIND_PACKAGE(Boost COMPONENTS chrono coroutine)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR} )
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

IF(${CMAKE_CXX_COMPILER} STREQUAL "C:/msys64/mingw64/bin/clang++.exe")
    message(${CMAKE_CXX_COMPILER})
    add_executable(coroutineTS coroutineTS.cpp)
ELSE()
    add_executable(chrono chrono.cpp)
    add_executable(coroutine2 coroutines.cpp)
    add_executable(asiocoroutine asioCoroutines.cpp)
    #add_executable(fiber fiber.cpp)
    add_executable(stacktrace stacktrace.cpp)


    target_link_libraries(chrono ${Boost_LIBRARIES})
    target_link_libraries(coroutine2 ${Boost_LIBRARIES})
    target_link_libraries(stacktrace ${Boost_LIBRARIES} "C:\\msys64\\mingw64\\lib\\libbacktrace.a")

ENDIF()




