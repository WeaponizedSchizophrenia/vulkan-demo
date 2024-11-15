#include "WindowManager.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>

wml::Library::Library() {
  if (glfwInit() == GLFW_FALSE) {
    throw std::runtime_error("Could not initialize glfw");
  }
}

wml::Library::~Library() noexcept { glfwTerminate(); }

auto wml::Window::Deleter::operator()(GLFWwindow* window) const noexcept -> void {
  glfwDestroyWindow(window);
}

wml::Window::Window(WindowCreateInfo info)
    : _window([=] {
      glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
      if (auto* const window = glfwCreateWindow(static_cast<int>(info.size.width),
                                                static_cast<int>(info.size.height),
                                                info.title, nullptr, nullptr)) {
        return window;
      } else {
        throw std::runtime_error("Could not create glfw window");
      }
    }()) {}
