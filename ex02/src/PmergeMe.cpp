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
		if (*endptr != '\0' || nb < 0 || nb > INT_MAX) {
			std::cerr << RED << "Error: " << R << args[i] << " is a invalid number" << std::endl;
			return false;
		}
	}
	return true;
}

void PmergeMe::sortVector(std::vector<int> &container) {
	mergeSortV(container.begin(), container.end());
}

void PmergeMe::sortDeque(std::deque<int> &container) {
	mergeSortD(container.begin(), container.end());
}

void PmergeMe::mergeSortV(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (end - begin > K) {
		std::vector<int>::iterator middle = begin + (end - begin) / 2;
		mergeSortV(begin, middle);
		mergeSortV(middle, end);
		mergeV(begin, middle, end);
	}
	else {
		insertionSortV(begin, end);
	}
}

void PmergeMe::mergeSortD(std::deque<int>::iterator begin, std::deque<int>::iterator end) {
	if (end - begin > K) {
		std::deque<int>::iterator middle = begin + (end - begin) / 2;
		mergeSortD(begin, middle);
		mergeSortD(middle, end);
		mergeD(begin, middle, end);
	}
	else {
		insertionSortD(begin, end);
	}
}

void PmergeMe::mergeV(std::vector<int>::iterator begin, std::vector<int>::iterator middle, std::vector<int>::iterator end) {
	std::vector<int> tmp;
	std::vector<int>::iterator it1 = begin;
	std::vector<int>::iterator it2 = middle;

	while (it1 != middle && it2 != end) {
		if (*it1 < *it2) {
			tmp.push_back(*it1);
			it1++;
		}
		else {
			tmp.push_back(*it2);
			it2++;
		}
	}
	while (it1 != middle) {
		tmp.push_back(*it1);
		it1++;
	}
	while (it2 != end) {
		tmp.push_back(*it2);
		it2++;
	}
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		*begin = *it;
		begin++;
	}
}

void PmergeMe::mergeD(std::deque<int>::iterator begin, std::deque<int>::iterator middle, std::deque<int>::iterator end) {
	std::deque<int> tmp;
	std::deque<int>::iterator it1 = begin;
	std::deque<int>::iterator it2 = middle;

	while (it1 != middle && it2 != end) {
		if (*it1 < *it2) {
			tmp.push_back(*it1);
			it1++;
		}
		else {
			tmp.push_back(*it2);
			it2++;
		}
	}
	while (it1 != middle) {
		tmp.push_back(*it1);
		it1++;
	}
	while (it2 != end) {
		tmp.push_back(*it2);
		it2++;
	}
	for (std::deque<int>::iterator it = tmp.begin(); it != tmp.end(); it++) {
		*begin = *it;
		begin++;
	}
}

void PmergeMe::insertionSortV(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	for (std::vector<int>::iterator it = begin; it != end; it++) {
		std::vector<int>::iterator it2 = it + 1;
		int tmp = *it2;
		while (it2 != begin && *(it2 - 1) > tmp) {
			*it2 = *(it2 - 1);
			it2--;
		}
		*it2 = tmp;
	}
}

void PmergeMe::insertionSortD(std::deque<int>::iterator begin, std::deque<int>::iterator end) {
	for (std::deque<int>::iterator it = begin; it != end; it++) {
		std::deque<int>::iterator it2 = it + 1;
		int tmp = *it2;
		while (it2 != begin && *(it2 - 1) > tmp) {
			*it2 = *(it2 - 1);
			it2--;
		}
		*it2 = tmp;
	}
}
