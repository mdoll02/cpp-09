#pragma once

#include <string>
#include <iostream>
#include "Colors.hpp"
#include <vector>

class PmergeMe {
public:
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

	static bool checkArgs(char **args);

	template<typename  T>
	static void fillContainer(T &container, char** args);
	template<typename T>
	static void printContainer(T &container);

	template<typename T>
	static long sort(T &container);

	template<typename T>
	static void FJSRT(T &container);

private:
	PmergeMe();
};
