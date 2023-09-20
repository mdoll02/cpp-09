#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	//std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	//std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		return *this;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	//std::cout << "BitcoinExchange destructor called" << std::endl;
}

const char *BitcoinExchange::InvalidFileException::what() const throw() {
	return "invalid file";
}
