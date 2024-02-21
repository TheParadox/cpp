#ifndef GLFW_WINDOW_HPP
#define GLFW_WINDOW_HPP

#include <GLFW/glfw3.h>

class GLFWwindow {
public:
	GLFWwindow();
	~GLFWwindow();

	void pollEvents();

private:
	GLFWwindow* m_pWindow = nullptr;

};

#endif //GLFW_WINDOW_HPP