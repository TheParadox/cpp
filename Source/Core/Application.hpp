#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Window/GLFWWindow.hpp"

class Application {
public:
	Application();
	~Application();

	void running();

	inline static Application& get() {
		return *s_pInstance;
	}

	void endProgram();

private:
	GLFWwindow* m_pMainWindow = nullptr;
	bool m_isRunning;

private:
	static Application* s_pInstance;
};

#endif //APPLICATION_HPP