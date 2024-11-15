#pragma once

#include <cstdint>
#include <memory>

struct GLFWwindow;

namespace wml {
struct WindowCreateInfo {
  struct {
    std::uint32_t width {};
    std::uint32_t height {};
  } size {};
  const char* title {};
};

class Library {
public:
  Library();
  ~Library() noexcept;

  Library(Library&&) = delete;
  Library(const Library&) = delete;
  auto operator=(Library&&) -> Library& = delete;
  auto operator=(const Library&) -> Library& = delete;
};

class Window {
  struct Deleter {
    auto operator()(GLFWwindow*) const noexcept -> void;
  };

public:
  Window() = delete;
  explicit Window(WindowCreateInfo);

private:
  std::unique_ptr<GLFWwindow, Deleter> _window;
};
} // namespace wml
