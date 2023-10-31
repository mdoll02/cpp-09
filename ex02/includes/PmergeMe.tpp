#pragma once

#include "PmergeMe.hpp"

#include <string>
#include <iostream>
#include "Colors.hpp"

template<typename T>
void PmergeMe::printContainer(T &container) {
	typename T::iterator it;

	for (it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " ";
		if (container.size() > 4 && it - container.begin() == 4) {
			std::cout << "[...]";
			break;
		}
	}
	std::cout << std::endl;
}

template<typename T>
void PmergeMe::fillContainer(T &container, char **args) {
	int nb;
	char *endptr;

	for (int i = 0; args[i]; i++) {
		nb = static_cast<int>(strtod(args[i], &endptr));
		container.push_back(nb);
	}
}

template<typename T>
bool PmergeMe::isSorted(T &container) {
	for (typename T::iterator it = container.begin(); it != container.end() - 1; it++) {
		if (*it > *(it + 1))
			return false;
	}
	return true;
}