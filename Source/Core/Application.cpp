#include "Application.hpp"

#include "TextParser.hpp"
#include "Math/BasicMath.hpp"

#include <iostream>


Application* Application::s_pInstance = nullptr;

Application::Application() {
	s_pInstance = this;

	m_pMainWindow = new GLFWwindow;

	if(m_pMainWindow == nullptr) {
		m_isRunning = false;
	} else {
		m_isRunning = true;
	}
}
Application::~Application() {
	delete m_pMainWindow;
}

void Application::running() {

	while(m_isRunning) {
		m_pMainWindow->pollEvents();
	}

	//using IO stream is temporary. Prototyping and proof of concept...
	/*std::cout << "Enter your math problem (numbers, +, -, *, /): ";
	std::string consoleInput;
	std::getline(std::cin, consoleInput);
	
	//std::cout << consoleInput << std::endl; //unless you know for certain its always going to work - leave commented outputs at critical locations.

	//Regardless of IOStream or GUI - still need to parse and perform math.
	std::vector<std::string> data = parseUserInput(consoleInput);
	float result = basicMath(data);

	//Temporary - until GUI is working
	std::cout  << "\nResult: " << result << std::endl;*/
}

void Application::endProgram() {
	m_isRunning = false;
}