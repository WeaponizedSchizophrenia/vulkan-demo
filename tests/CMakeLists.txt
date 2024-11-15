CPMAddPackage("gh:catchorg/Catch2@3.7.1")

add_executable(tests)
target_compile_features(tests PRIVATE cxx_std_23)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain window_manager)

target_sources(tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Sanity.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/WindowManagerTests.cpp
)

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests)
