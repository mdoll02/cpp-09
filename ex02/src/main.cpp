#include "PmergeMe.hpp"
#include "PmergeMe.tpp"
#include <deque>

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << RED << "Error: " << R << "Invalid number of arguments" << std::endl;
		return 1;
	}
	if (!PmergeMe::checkArgs(argv + 1)) {
		return 1;
	}
	std::vector<int> vec;
	std::deque<int> deq;
	PmergeMe::fillContainer(vec, argv + 1);
	PmergeMe::fillContainer(deq, argv + 1);
	std::cout << GREEN << "Before sort: " << R;
	PmergeMe::printContainer(vec);
	clock_t startVec = clock();
	PmergeMe::sortVector(vec);
	clock_t endVec = clock();
	clock_t startDeque = clock();
	PmergeMe::sortDeque(deq);
	clock_t endDeque = clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
	double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector<int>: " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque<int>: " << timeDeque << " us" << std::endl;
	std::cout << GREEN << "Vector after sort: " << R;
	PmergeMe::printContainer(vec);
	if (!PmergeMe::isSorted(vec))
		std::cout << RED << "Vector is not sorted" << R << std::endl;
	else
		std::cout << GREEN << "Vector is sorted" << R << std::endl;
	std::cout << GREEN << "Deque after sort: " << R;
	PmergeMe::printContainer(deq);
	if (!PmergeMe::isSorted(deq))
		std::cout << RED << "Deque is not sorted" << R << std::endl;
	else
		std::cout << GREEN << "Deque is sorted" << R << std::endl;
}

// ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`