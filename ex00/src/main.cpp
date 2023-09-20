#include "BitcoinExchange.hpp"
#include <sstream>

static bool valid_line(std::string &line) {
	std::istringstream iss(line);
	std::string datePart, ratePart, delim;

	if (!(iss >> datePart >> delim >> ratePart) || delim != "|" || datePart.size() != 10)
		return false;
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
	while (std::getline(file, line)) {
		if (first && line == "date | value") {
			first = false;
			continue;
		}
		if (valid_line(line)) {
			std::cout << line << std::endl;
		}
		else {
			std::cerr << RED << "Error: " << R << "invalid line" << std::endl;
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