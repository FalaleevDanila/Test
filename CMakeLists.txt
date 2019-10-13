cmake_minimum_required(VERSION 3.14)
project(Kursach)

set(CMAKE_CXX_STANDARD 17)

add_executable(Kursach main.cpp)

#SFML
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

#OPENGL
find_package(OpenGL REQUIRED)
if (OpenGL_FOUND)
    include_directories(${OpenGL_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${OpenGL_LIBRARIES})
    target_link_libraries(${PROJECT_NAME} GL)
endif()

find_package(GLEW 2.0 REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARIES})
endif()