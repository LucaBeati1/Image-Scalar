cmake_minimum_required(VERSION 3.15)

project(imageScalar)
set(CMAKE_CXX_STANDARD 20)
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME})

add_subdirectory("thirdParty/raylib")
target_sources(${PROJECT_NAME} PRIVATE ${MY_SOURCES} )
target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries(${PROJECT_NAME} PUBLIC raylib)