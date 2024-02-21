#include "Core/Application.hpp"
#include "Core/Log.hpp"

int main(int argc, char** argv) {

	LOG::init(); //We need to make sure the logger is initialized before starting anything and everything that relies on it

	CR_TRACE("Hello from the logger");

	Application app; //Could/should change to a pointer. Right now its small enough that its okay on the stack.

	app.running();

	//Should actually have the app functions return a code upon completion and return that.
	//As right now this error code is almost useless...
	return 0;
}