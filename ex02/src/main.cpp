#include "PmergeMe.hpp"
#include "PmergeMe.tpp"
#include <deque>


#include <algorithm>
#include <random>

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << RED << "Error: " << R << "Invalid number of arguments" << std::endl;
		return 1;
	}
	if (!PmergeMe::checkArgs(argv)) {
		return 1;
	}
	std::vector<int> vec;
	std::deque<int> deq;
	PmergeMe::fillContainer(vec, argv);
	PmergeMe::fillContainer(deq, argv);
	std::cout << GREEN << "Before sort: " << R;
	PmergeMe::printContainer(vec);
	long timeVec = PmergeMe::sort(vec);
	long timeDeque = PmergeMe::sort(deq);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector<int>: " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::deque<int>: " << timeDeque << " us" << std::endl;
	std::cout << GREEN << "After sort: " << R;
	PmergeMe::printContainer(vec);
}