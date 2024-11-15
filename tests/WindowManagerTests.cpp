#include "WindowManager.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("wml::Library", "[wml]") {
  [[maybe_unused]]
  const wml::Library library;
}

TEST_CASE("wml::Window", "[wml]") {
  [[maybe_unused]]
  const wml::Library library;
  const wml::Window window({
      .size =
          {
              .width = 800,
              .height = 600,
          },
      .title = "Window",
  });
}
