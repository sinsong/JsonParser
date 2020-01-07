cmake_minimum_required(VERSION 3.4.3)

project(JsonParser)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(lib)
add_subdirectory(test)