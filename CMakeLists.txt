cmake_minimum_required(VERSION 3.9)

project(cis1_cwu_protocol)

find_package(Threads REQUIRED)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE include)

include_directories(${CMAKE_SOURCE_DIR}/include)

if(BUILD_TESTING)
    add_subdirectory(test_package)
endif(BUILD_TESTING)
