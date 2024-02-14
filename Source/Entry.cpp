#include "Core/Application.hpp"

int main(int argc, char** argv) {

	Application app; //Could/should change to a pointer. Right now its small enough that its okay on the stack.

	app.init();
	app.running();
	app.shutdown();

	//Should actually have the app functions return a code upon completion and return that.
	//As right now this error code is almost useless...
	return 0;
}