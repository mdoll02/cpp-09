#pragma once

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include "Colors.hpp"

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

	void fillDatabase();
	void fillRates(std::string &fileName);
	void calculateRates();


	void printRates();
	void printRate(std::string &date);


class InvalidFileException : public std::exception {
public:
	virtual const char* what() const throw();
};
private:
	std::map<std::string, double> _database;
	std::map<std::string, double> _rates;
};
