#include "BasicMath.hpp"

float basicMath(std::vector<std::string> a_inputs) {
	std::vector<float> inputs;
	std::vector<std::string> operands;

	float total = 0.0f;

	//Lets makes sure we actually got some inputs before trying to convert and process...
	if(a_inputs[0] == "") {
		return 0.0f;
	}


	//Need to see if a better way of handling this exists/is possible. 
	inputs.push_back(stof(a_inputs[0]));
	for(uint32_t i = 1; i < a_inputs.size(); i += 2) {
		operands.push_back(a_inputs[i]);
		inputs.push_back(stof(a_inputs[i + 1]));
	}

	
	//We need to iterate over the operands based on order of operation. However, is there a better way of doing this?
	//Instead of iterating over the vector twice? What about when other operations get added such as parenthesis, exponents, etc...

	for(uint32_t i = 0; i < operands.size(); i++) {
		if(operands[i] == "*") {
			inputs[i] *= inputs[i + 1];
			inputs.erase(inputs.begin() + i + 1);
			operands.erase(operands.begin() + i);
			i--;
		} else if(operands[i] == "/") {
			inputs[i] /= inputs[i + 1];
			inputs.erase(inputs.begin() + i + 1);
			operands.erase(operands.begin() + i);
			i--;
		}
	}

	total = inputs[0];
	for(uint32_t i = 0; i < operands.size(); i++) {
		if(operands[i] == "+") {
			total += inputs[i + 1];
		} else if(operands[i] == "-") {
			total -= inputs[i + 1];
		}
	}

	return total;
}