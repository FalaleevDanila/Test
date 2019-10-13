cmake_minimum_required(VERSION 3.14)
project(Kursach)

set(CMAKE_CXX_STANDARD 17)

add_executable(Kursach main.cpp)

message (INFO ${SFML_LIBRARIES})
# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Kursach ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} glu)
endif()

