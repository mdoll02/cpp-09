#pragma once

#include <stack>
#include <algorithm>
#include <string>
#include <iostream>
#include "Colors.hpp"

class RPN {
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

	void addToken(std::string &token);

	int getResult();

class InvalidTokenException : public std::exception {
public:
	virtual const char* what() const throw();
};

class TooManyResults : public std::exception {
public:
	virtual const char* what() const throw();
};
private:
	std::stack<int> _stack;
	bool is_valid(std::string &token, bool &is_operator);
    
};
