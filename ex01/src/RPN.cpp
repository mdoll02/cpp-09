#include "RPN.hpp"

RPN::RPN() {
	// std::cout << "RPN constructor called" << std::endl;
}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other) {
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {
	//std::cout << "RPN destructor called" << std::endl;
}

void RPN::addToken(std::string &token) {
	bool is_operator = false;
	if (!is_valid(token, is_operator)) {
		throw InvalidTokenException();
	}
	if (is_operator) {
		if (_stack.size() < 2) {
			throw InvalidTokenException();
		}
		int b = _stack.top();
		_stack.pop();
		int a = _stack.top();
		_stack.pop();
		switch (token[0]) {
			case '+':
				_stack.push(a + b);
				break;
			case '-':
				_stack.push(a - b);
				break;
			case '*':
				_stack.push(a * b);
				break;
			case '/':
				_stack.push(a / b);
				break;
			default:
				throw InvalidTokenException();
		}
	}
	else {
		_stack.push(atoi(token.c_str()));
	}
}

bool RPN::is_valid(std::string &token, bool &is_operator) {
	if (token.length() != 1)
		return false;
	if (isdigit(token[0])) {
		return true;
	}
	is_operator = true;
	return true;
}

int RPN::getResult() {
	if (_stack.size() > 1) {
		throw TooManyResults();
	}
	return _stack.top();
}


const char *RPN::InvalidTokenException::what() const throw() {
	return "Invalid token";
}

const char *RPN::TooManyResults::what() const throw() {
	return "Multiple numbers on Stack";
}
