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
		for(std::map<std::string, double>::const_iterator it = other._database.begin(); it != other._database.end(); ++it) {
			this->_database[it->first] = it->second;
		}
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {
	//std::cout << "BitcoinExchange destructor called" << std::endl;
}

void BitcoinExchange::fillDatabase() {
	std::ifstream file("data.csv");
	std::string line;
	std::string date;
	double rate;
	char *endptr;


	if (!file.is_open())
		throw InvalidFileException();
	getline(file, line);
	while (std::getline(file, line)) {
		date = line.substr(0, line.find(','));
		rate = strtod(line.substr(line.find(',') + 1).c_str(), &endptr);
		if (*endptr != '\0') {
			std::cerr << RED << "Error: " << R << "invalid price for date " << date << std::endl;
			continue;
		}
		this->_database[date] = rate;
	}
}

void BitcoinExchange::printRates() {
	for(std::map<std::string, double>::const_iterator it = this->_database.begin(); it != this->_database.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

void BitcoinExchange::printRate(std::string &date) {
	std::map<std::string, double>::const_iterator it = this->_database.find(date);

	if (it == this->_database.end()) {
		std::cerr << RED << "Error: " << R << "invalid date" << std::endl;
		return;
	}
	std::cout << it->first << ": " << it->second << std::endl;
}

void BitcoinExchange::fillRates(std::string &fileName) {
	std::ifstream file (fileName);
	std::string line;
	std::string date;
	double rate;
	char *endptr;
	bool firstLine = true;

	if (!file.is_open())
		throw InvalidFileException();
	while (std::getline(file, line)) {
		if (firstLine && line == "data | value") {
			firstLine = false;
			continue;
		}
		date = line.substr(0, line.find('|'));
		rate = strtod(line.substr(line.find(',') + 1).c_str(), &endptr);
		if (date.empty()) {
			std::cerr << RED << "Error: " << R << "invalid date" << std::endl;
			continue;
		}
		if (*endptr != '\0') {
			std::cerr << RED << "Error: " << R << "invalid rate for date " << date << std::endl;
			continue;
		}
		if (rate < 0) {
			std::cout << RED << "Error: " << R << "negative rate for date " << date << std::endl;
			rate = NAN;
		}
		else if (rate > 1000) {
			std::cout << RED << "Error: " << R << "rate too high for date " << date << std::endl;
			rate = NAN;
		}
		this->_rates[date] = rate;
	}
}

void BitcoinExchange::calculateRates() {

}


const char *BitcoinExchange::InvalidFileException::what() const throw() {
	return "invalid file";
}
