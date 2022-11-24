cmake_minimum_required(VERSION 3.19)
project(datastruct-exp)

set(CMAKE_CXX_STANDARD 14)

# 本地的include和lib目录
set(LOCAL_INC_DIR "F:/Program Files (x86)/EGE20.08/include")
set(LOCAL_LINK_DIR "F:/Program Files (x86)/EGE20.08/lib/mingw64")

set(EGE_INC_DIR ${LOCAL_INC_DIR})
set(EGE_LINK_DIR ${LOCAL_LINK_DIR})
set(PROJECT_INC_DIR ${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EGE_LIB libgraphics64.a
        libgdi32.a libimm32.a libmsimg32.a libole32.a
        liboleaut32.a libwinmm.a libuuid.a libgdiplus.a
        )

include_directories(${EGE_INC_DIR}
        ${PROJECT_INC_DIR}
        )
link_directories(${EGE_LINK_DIR})

aux_source_directory(./src SOURCE)
add_library(${PROJECT_NAME} SHARED
        ${SOURCE}
        )

add_executable(demo-dfs example/demo.cpp)
target_link_libraries(demo-dfs
        ${PROJECT_NAME}
        ${EGE_LIB}
)



