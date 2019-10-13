cmake_minimum_required(VERSION 3.0)
project(Kursach)

set(CMAKE_CXX_STANDARD 17)

add_executable(Kursach main.cpp)

#SFML
find_package(SFML REQUIRED system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(
      ${PROJECT_NAME}
      sfml-audio
      sfml-system
      sfml-network
      sfml-window
      sfml-graphics
    )
endif()

#OPENGL
find_package(OpenGL REQUIRED)
if (OpenGL_FOUND)
    include_directories(${OpenGL_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${OpenGL_LIBRARIES})

endif()

find_package(GLEW 2.0 REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${GLEW_LIBRARIES})
endif()

target_link_libraries(
  ${PROJECT_NAME}
  GL
  GLU
  glut
)
