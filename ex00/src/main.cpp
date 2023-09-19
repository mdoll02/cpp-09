#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << RED << "Error: " << R << "invalid number of arguments" << std::endl;
		return 1;
	}

	std::cout << "getting rates for " << argv[1] << std::endl;
	BitcoinExchange btc;
	std::string file = argv[1];

	try {
		btc.fillDatabase();
		btc.fillRates(file);
		btc.printRates();
		btc.calculateRates();
	} catch (std::exception &e) {
		std::cerr << RED << "Error: " << R << e.what() << std::endl;
		return 1;
	}
	return 0;
}

// TODO: input data = exchange rate for each day
//		if date does not exist choose the next LOWER date
//		if date is before the first date choose the first date or print error
//		if date is after the last date choose the last date or print error
//		if date is invalid or doesnt follow syntax print error

//todo	print the exchange rate for the given date