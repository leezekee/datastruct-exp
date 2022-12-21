cmake_minimum_required(VERSION 3.19)
project(datastruct-exp)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-mwindows)


set(PROJECT_INC_DIR ${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(NEEDED_LIB libgraphics64.a
        libgdi32.a libimm32.a libmsimg32.a libole32.a
        liboleaut32.a libwinmm.a libuuid.a libgdiplus.a
        )

include_directories(${PROJECT_INC_DIR}
        )
link_directories(${PROJECT_SOURCE_DIR}/lib)


## 生成dll
aux_source_directory(./src SOURCE)
aux_source_directory(./include INCLUDE)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000")



add_library(${PROJECT_NAME} STATIC ${SOURCE} ${INCLUDE})
install(TARGETS ${PROJECT_NAME} DESTINATION  ${PROJECT_SOURCE_DIR}/lib)
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C
        OUTPUT_NAME ${PROJECT_NAME}
        PREFIX "")

add_executable(demo-test example/demo-test.cpp)
target_link_libraries(demo-test
        ${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/lib
        ${NEEDED_LIB}
)
add_executable(draw-array-test example/draw-array-test.cpp)
target_link_libraries(draw-array-test
        ${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/lib
        ${NEEDED_LIB}
        )
add_executable(dfs-test example/dfs-test.cpp)
target_link_libraries(dfs-test
        ${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/lib
        ${NEEDED_LIB}
        )
add_executable(bfs-test example/bfs-test.cpp)
target_link_libraries(bfs-test
        ${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/lib
        ${NEEDED_LIB}
        )
add_executable(gui-test example/gui-test.cpp)
target_link_libraries(gui-test
        ${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/lib
        ${NEEDED_LIB}
        )
add_executable(visualization-of-bfs-and-dfs example/visualization-of-bfs-and-dfs.cpp)
target_link_libraries(visualization-of-bfs-and-dfs
        ${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/lib
        ${NEEDED_LIB}
        )