
cmake_minimum_required(VERSION 3.1)
file( GLOB APP_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc)
# message(STATUS "APP_SOURCES = ${APP_SOURCES}")
# file( GLOB LIB_SOURCES ${CMAKE_SOURCE_DIR}/lib *.cc)
# include_directories(${CMAKE_SOURCE_DIR}/include)
# add_library(mylib ${LIB_SOURCES})

foreach(APP_NAME  ${APP_SOURCES})
#	message(STATUS "APP_NAME = ${APP_NAME}")
	get_filename_component(APP ${APP_NAME} NAME_WE)
        link_libraries(mylib) 
	message(STATUS "APP = ${APP}")
	add_executable(${APP} ${APP_NAME})
#	target_link_libraries(${APP} ${mylib})
endforeach()



