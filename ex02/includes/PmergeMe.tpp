#pragma once

#include "PmergeMe.hpp"

#include <string>
#include <iostream>
#include "Colors.hpp"
#include <vector>

template<typename T>
void PmergeMe::printContainer(T &container) {
	std::vector<int>::const_iterator it;

	if (container.begin() == container.end()) {
		std::cout << *container.begin() << std::endl;
		return;
	}
	for (it = container.begin(); it != container.end(); it++) {
		std::cout << *it << " ";
		if (it - container.begin() == 4) {
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
