cmake_minimum_required(VERSION 3.1)

project(CPP_Prime)

include_directories(${CMAKE_SOURCE_DIR}/include)

link_directories(${CMAKE_SOURCE_DIR}/lib)

# 指定静态库编译输出目录
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
# 指定编译输出目录
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/before11)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/11)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/12)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/13)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/14)



