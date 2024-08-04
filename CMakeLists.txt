cmake_minimum_required(VERSION 3.29.6)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(HelloWorld CXX)

find_package(fmt CONFIG REQUIRED)

add_executable(HelloWorld main.cpp)

target_link_libraries(HelloWorld PRIVATE fmt::fmt)
