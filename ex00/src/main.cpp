#include "BitcoinExchange.hpp"
#include <sstream>

static bool validDate(std::string &date) {
	if (date.size() != 10) {
		return false;
	}
	int year, month, day;
	std::istringstream iss(date);
	char delim;
	if (!(iss >> year >> delim >> month >> delim >> day) || delim != '-') {
		return false;
	}
	if (month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}
	return true;
}

static bool valid_line(std::string &line, std::string &datePart, double &rate) {
	std::istringstream iss(line);
	std::string ratePart, delim;

	datePart.clear();
	if (!(iss >> datePart >> delim >> ratePart) || delim != "|") {
		std::cerr << datePart << RED << " Error: " << R;
		if (delim != "|") {
			std::cerr << "Invalid delimiter";
		} else {
			std::cerr << "Bad Input";
		}
		std::cerr << std::endl;
		return false;
	}
	if (!validDate(datePart)) {
		std::cerr << datePart << RED << " Error: " << R << "Invalid Date" << std::endl;
		return false;
	}
	char* endptr;
	rate = std::strtod(ratePart.c_str(), &endptr);
	if (*endptr != '\0' || rate < 0 || rate > 1000) {
		std::cerr << datePart << RED << " Error: " << R;
		if (*endptr != '\0') {
			std::cerr << "Invalid Rate";
		} else if (rate < 0) {
			std::cerr << "Rate too small";
		} else {
			std::cerr << "Rate too big";
		}
		std::cerr << std::endl;
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
