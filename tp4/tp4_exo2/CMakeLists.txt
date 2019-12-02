cmake_minimum_required(VERSION 2.8)

project(tp4_exo2)
cmake_minimum_required(VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
 add_compile_options(-Wall -Wpedantic -Werror)
endif()



add_executable(${PROJECT_NAME} "main.cc" document.cc periodique.cc livre.cc video.cc documentmanuscrit.cc bibliotheque.cc)
