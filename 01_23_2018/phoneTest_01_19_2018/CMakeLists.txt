cmake_minimum_required(VERSION 2.8.3)
project(testPhone)

SET(CMAKE_CXX_COMPILER "g++")
SET( CMAKE_BUILD_TYPE Release )
SET( CMAKE_CXX_FLAGS "-O3 -std=c++11" )

include_directories(
  '/home/jin/Packages/libserial/src'
)
link_directories(
	'/home/jin/Packages/libserial/src'
)

add_library( myPhone SHARED src/myPhone.cpp)
target_link_libraries(myPhone -lboost_unit_test_framework /home/jin/Packages/libserial/src/.libs/libserial.so.0)

add_executable(testPhone src/testPhone.cpp)
target_link_libraries(testPhone myPhone -lboost_unit_test_framework /home/jin/Packages/libserial/src/.libs/libserial.so.0)