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

template<typename T>
long PmergeMe::sort(T &container) {
	time_t start, end;
	time(&start);
	FJSRT(container);
	time(&end);
	return end - start;
}

template<typename T>
void PmergeMe::FJSRT(T &container) {
	std::vector<std::vector<int> > pairs;
	int lonelyNumber, tmp = -1;
	typename T::iterator it;
	std::vector<std::vector<int> >::iterator itPairs;

	if (container.size() % 2 != 0) {
		lonelyNumber = container.back();
		container.pop_back();
	}
	for (it = container.begin(); it != container.end(); it += 2) {
		std::vector<int> pair;
		pair.push_back(*it);
		pair.push_back(*(it + 1));
		pairs.push_back(pair);
	}
	for (itPairs = pairs.begin(); itPairs != pairs.end(); itPairs++) {
		if ((*itPairs)[0] > (*itPairs)[1]) {
			tmp = (*itPairs)[0];
			(*itPairs)[0] = (*itPairs)[1];
			(*itPairs)[1] = tmp;
		}
	}

	

}
