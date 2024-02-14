#include "TextParser.hpp"

std::vector<std::string> parseUserInput(std::string a_userConsoleInput) {

	std::vector<std::string> inputsList;
	uint32_t numberOfInputs = 0;

	//This is temporary - ideally would go with something else, like Regex to split the string.
	//However, Also need to consider how to handle other math functionallity such as parenthises.
	inputsList.push_back("");
	for(uint32_t i = 0; i < a_userConsoleInput.size(); i++) {
		if(a_userConsoleInput[i] == '+' ||
			a_userConsoleInput[i] == '-' ||
			a_userConsoleInput[i] == '*' ||
			a_userConsoleInput[i] == '/') {
				inputsList.push_back(std::string(1, a_userConsoleInput[i]));
				inputsList.push_back("");
				numberOfInputs += 2;
		} else if(a_userConsoleInput[i] == ' ') {
			continue; //We want to remove extra whitespaces...
		} else {
			inputsList[numberOfInputs] += a_userConsoleInput[i];
		}

	}

	//Critical operation... Make sure users string got properly converted.
	/*for(uint32_t i = 0; i <= numberOfInputs; i++){
		std::cout << inputsList[i] << std::endl;
	}*/


	return inputsList;
}