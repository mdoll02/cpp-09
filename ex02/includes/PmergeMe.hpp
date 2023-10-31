#pragma once

#include <string>
#include <iostream>
#include "Colors.hpp"
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <climits>


#ifndef K
# define K 4
#endif

class PmergeMe {
public:
    ~PmergeMe();

	static bool checkArgs(char **args);

	template<typename  T>
	static void fillContainer(T &container, char** args);
	template<typename T>
	static void printContainer(T &container);

	static void sortVector(std::vector<int> &vector);

	static void sortDeque(std::deque<int> &container);

private:

	static void mergeSortV(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	static void mergeV(std::vector<int>::iterator begin, std::vector<int>::iterator middle, std::vector<int>::iterator end);

	static void insertionSortV(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	static void mergeSortD(std::deque<int>::iterator begin, std::deque<int>::iterator end);

	static void mergeD(std::deque<int>::iterator begin, std::deque<int>::iterator middle, std::deque<int>::iterator end);

	static void insertionSortD(std::deque<int>::iterator begin, std::deque<int>::iterator end);

	PmergeMe();
};
