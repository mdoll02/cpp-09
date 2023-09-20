#include "RPN.hpp"
#include "Colors.hpp"
#include <iostream>
#include <sstream>

int main (int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED << "Error: " << R << "Invalid number of arguments" << std::endl;
		return 1;
	}
	if (argv[1][0] == '\0') {
		std::cerr << RED << "Error: " << R << "Argument cant be empty" << std::endl;
		return 1;
	}
	RPN rpn;
	std::stringstream ss;
	std::string token;
	ss << argv[1];

	while (std::getline(ss, token, ' ')) {
		try {
			rpn.addToken(token);
		} catch (std::exception &e){
			std::cerr << RED << "Error: " << R << e.what() << std::endl;
			return(1);
		}
	}
	try {
		int result = rpn.getResult();
		std::cout << GREEN << "Result: " << R << result << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Error: " << R << e.what() << std::endl;
	}
	return (0);
}

// todo ./RPN "" segfault :(