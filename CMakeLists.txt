cmake_minimum_required (VERSION 3.8)

set(project_name helib_wavtest)
project(${project_name})


#list of src
set(src_list
	audio_extract.cpp
	)

find_package(helib REQUIRED)

#add /usr/lib/libaudiofile.so
find_library(AUDIOFILE_LIB audiofile)
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost REQUIRED COMPONENTS program_options)

list(TRANSFORM src_list PREPEND src/)
#debug src_list
message(STATUS "src_list: ${src_list}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(${project_name} STATIC ${src_list})
target_link_libraries(${project_name} helib audiofile ${Boost_LIBRARIES})

add_executable(${project_name}_exe src/main.cpp)
target_link_libraries(${project_name}_exe ${project_name}  ${Boost_LIBRARIES})

