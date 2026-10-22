cmake_minimum_required(VERSION 3.12)
project(canny)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(SOURCES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/res/pic.png
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR})