#include "BitcoinExchange.hpp"
#include <sstream>

static bool valid_line(std::string &line, std::string &datePart, double &rate) {
	std::istringstream iss(line);
	std::string ratePart, delim;

	datePart.clear();
	if (!(iss >> datePart >> delim >> ratePart)) {
		std::cerr << datePart << RED << " Error: " << R << "Bad Input" << std::endl;
		return false;
	} else if (delim != "|") {
		std::cerr << datePart << RED << " Error: " << R << "Invalid delimiter" << std::endl;
		return false;
	} else if (datePart.size() != 10) {
		std::cerr << datePart << RED << " Error: " << R << "Invalid Date" << std::endl;
		return false;
	}
	char* endptr;
	rate = std::strtod(ratePart.c_str(), &endptr);
	if (*endptr != '\0') {
		std::cerr << datePart << RED << " Error: " << R << "Invalid Rate" << std::endl;
		return false;
	} else if (rate < 0) {
		std::cerr << datePart << RED << " Error: " << R << "Rate too small" << std::endl;
		return false;
	} else if (rate > 1000) {
		std::cerr << datePart << RED << " Error: " << R << "Rate too big" << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED << "Error: " << R << "invalid number of arguments" << std::endl;
		return 1;
	}

	std::cout << "getting rates for " << argv[1] << std::endl;
	BitcoinExchange btc;
	try {
		btc.read_data("data.csv");
	} catch (std::exception &e) {
		std::cerr << RED << "Error: " << R << e.what() << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cerr << RED << "Error: " << R << "invalid file" << std::endl;
		return 1;
	}
	std::string line;
	bool first = true;
	std::string datePart;
	double rate = 0.0;
	while (std::getline(file, line)) {
		if ((first && line == "date | value") || line.empty()) {
			first = false;
			continue;
		}
		if (valid_line(line, datePart, rate)) {
			std::cout << line << " ==> " << rate * btc.getPrice(datePart) << std::endl;
		}
	}
	return 0;
}

// TODO: input data = exchange rate for each day
//		if date does not exist choose the next LOWER date
//		if date is before the first date choose the first date or print error
//		if date is after the last date choose the last date or print error
//		if date is invalid or doesnt follow syntax print error

//todo	print the exchange rate for the given date