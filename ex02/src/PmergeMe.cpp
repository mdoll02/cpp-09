#include "PmergeMe.hpp"

PmergeMe::PmergeMe() { }

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() { }

bool PmergeMe::checkArgs(char **args) {
	char* endptr;
	double nb;

	for (int i = 0; args[i]; i++) {
		nb = std::strtod(args[i], &endptr);
		if (*endptr != '\0' || nb < 0 || nb > INT32_MAX) {
			std::cerr << RED << "Error: " << R << args[i] << " is a invalid number" << std::endl;
			return false;
		}
	}
	return true;
}
