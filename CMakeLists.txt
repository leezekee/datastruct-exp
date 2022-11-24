cmake_minimum_required(VERSION 3.19)
project(dataStruct_exp)

set(EGE_INC_DIR "F:/Program Files (x86)/EGE20.08/include")
set(EGE_LINK_DIR "F:/Program Files (x86)/EGE20.08/lib/mingw64")

include_directories(${EGE_INC_DIR})
link_directories(${EGE_LINK_DIR})

set(CMAKE_CXX_STANDARD 14)

add_executable(dataStruct_exp main.cpp)