cmake_minimum_required(VERSION 3.19)
project(datastruct-exp)

set(CMAKE_CXX_STANDARD 14)


set(PROJECT_INC_DIR ${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
#set(CMAKE_INSTALL_RPATH ./lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(NEEDED_LIB libgraphics64.a
        libgdi32.a libimm32.a libmsimg32.a libole32.a
        liboleaut32.a libwinmm.a libuuid.a libgdiplus.a
        )

include_directories(${PROJECT_INC_DIR}
#        ${PROJECT_INC_DIR}/ege
        )
link_directories(${PROJECT_SOURCE_DIR}/lib)

#aux_source_directory(./src SOURCE)
#
## 生成dll
#add_library(${PROJECT_NAME} SHARED ${SOURCE} ${PROJECT_INC_DIR})
#install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/lib)
#SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C)
aux_source_directory(./src SOURCE)
aux_source_directory(./include INCLUDE)

# 生成dll
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




