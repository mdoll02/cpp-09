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
		for (std::map<std::string, double>::const_iterator it = other._data.begin(); it != other._data.end(); it++) {
			_data[it->first] = it->second;
		}
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	//std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::read_data(const char *database) {
	std::ifstream file(database);
	if (!file.is_open()) {
		throw InvalidFileException();
	}
	std::string line;
	char *endptr;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::string date = line.substr(0, line.find(','));
		double rate = std::strtod(line.substr(line.find(',') + 1).c_str(), &endptr);
		if (*endptr != '\0') {
			throw InvalidDataRateException();
		}
		_data[date] = rate;
	}
}

double BitcoinExchange::getPrice(std::string date) {
	std::map<std::string, double>::iterator it = _data.upper_bound(date);

	if (it != _data.begin()) {
		it--;
	}
	return it->second;
}

const char *BitcoinExchange::InvalidFileException::what() const throw() {
	return "invalid file";
}

const char *BitcoinExchange::InvalidDataRateException::what() const throw() {
	return "Invalid rate in Dataset";
}
