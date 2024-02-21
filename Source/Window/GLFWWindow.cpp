#include "GLFWWindow.hpp"

#include "Core/Log.hpp"
#include "Core/Application.hpp"

static bool s_GLFWInitialized = false;

static void GLFWErrorCallback(int a_error, const char* a_description) {
	CR_FAULT("GLFW Error: ({0}) - {1}", a_error, a_description);
}

GLFWwindow::GLFWwindow() {

	if(!s_GLFWInitialized) {
		int success = glfwInit();
		CR_ASSERT(success, "Could not initialize GLFW");
		glfwSetErrorCallback(GLFWErrorCallback);
		s_GLFWInitialized = true;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_pWindow = glfwCreateWindow(480, 620, "CPP Calculator", nullptr, nullptr);
	if(m_pWindow == nullptr) {
		CR_FATAL("Failed to create GLFW Window");
		glfwTerminate();
		return;
	}

	glfwSetWindowCloseCallback(m_pWindow, [](GLFWwindow* a_window) {
		Application::get().endProgram();
	});

}

GLFWwindow::~GLFWwindow() {
	if(m_pWindow) {
		glfwDestroyWindow(m_pWindow);
		glfwTerminate();
	}
}

void GLFWwindow::pollEvents() {
	glfwSwapBuffers(m_pWindow);
	glfwPollEvents();
}