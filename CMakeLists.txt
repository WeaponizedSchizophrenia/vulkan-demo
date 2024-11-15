cmake_minimum_required(VERSION 3.30)
project(VulkanDemo LANGUAGES CXX C)

include(cmake/CPM.cmake)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
