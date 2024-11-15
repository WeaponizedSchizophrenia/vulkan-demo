CPMAddPackage("gh:glfw/glfw#3.3.9")

add_library(window_manager STATIC)
target_compile_features(window_manager PUBLIC cxx_std_23)

target_link_libraries(window_manager PRIVATE glfw)

target_include_directories(window_manager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(window_manager PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/WindowManager.cpp
)
