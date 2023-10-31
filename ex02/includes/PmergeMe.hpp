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

	template<typename T>
	static bool isSorted(T &container);

	static void sortVector(std::vector<int> &vector);

	static void sortDeque(std::deque<int> &container);

private:

	static void mergeSortV(int begin, int end, std::vector<int> &vector);

	static void mergeV(int begin, int mid, int end, std::vector<int> &vector);

	static void insertionSortV(int begin, int end, std::vector<int> &vector);

	static void mergeSortD(int begin, int end, std::deque<int> &deque);

	static void mergeD(int begin, int mid, int end, std::deque<int> &deque);

	static void insertionSortD(int begin, int end, std::deque<int> &deque);

	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
};
