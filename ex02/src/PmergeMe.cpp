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

void	PmergeMe::sortVector(std::vector<int> &vector) {
	sortV(0, static_cast<int>(vector.size() - 1), vector);
}

void	PmergeMe::sortV(int begin, int end, std::vector<int> &vector) {
	if (end - begin > K) {
		int mid = (begin + end) / 2;
		sortV(begin, mid, vector);
		sortV(mid + 1, end, vector);
		mergeV(begin, mid, end, vector);
	}
	else {
		insertionSortV(begin, end, vector);
	}
}

void	PmergeMe::mergeV(int begin, int mid, int end, std::vector<int> &vector) {
	int i;
	int j;
	int v1Length = mid - begin + 1;
	int v2Length = end - mid;
	int vectorIter = begin;
	std::vector<int> v1(v1Length), v2(v2Length);

	for (i = 0; i < v1Length; ++i)
		v1[i] = vector[begin + i];
	for (i = 0; i < v2Length; ++i)
		v2[i] = vector[mid + 1 + i];

	i = 0;
	j = 0;
	while(i < v1Length && j < v2Length) {
		if (v1[i] <= v2[j])
			vector[vectorIter] = v1[i++];
		else
			vector[vectorIter] = v2[j++];
		++vectorIter;
	}
	while (i < v1Length)
		vector[vectorIter++] = v1[i++];
	while (j < v2Length)
		vector[vectorIter++] = v2[j++];
}

void	PmergeMe::insertionSortV(int begin, int end, std::vector<int> &vector) {
	for (int i = begin; i < end; i++) {
		int j = i + 1;
		int tmp = vector[j];
		while (j > begin && vector[j - 1] > tmp) {
			vector[j] = vector[j - 1];
			--j;
		}
		vector[j] = tmp;
	}
}

void	PmergeMe::sortDeque(std::deque<int> &deque) {
	sortD(0, static_cast<int>(deque.size() - 1), deque);
}

void	PmergeMe::sortD(int begin, int end, std::deque<int> &deque) {
	if (end - begin > K) {
		int mid = (begin + end) / 2;
		sortD(begin, mid, deque);
		sortD(mid + 1, end, deque);
		mergeD(begin, mid, end, deque);
	}
	else {
		insertionSortD(begin, end, deque);
	}
}


void	PmergeMe::mergeD(int begin, int mid, int end, std::deque<int> &deque) {
	int i;
	int j;
	int d1Length = mid - begin + 1;
	int d2Length = end - mid;
	int dequeIter = begin;
	std::deque<int> d1(d1Length), d2(d2Length);

	for (i = 0; i < d1Length; ++i)
		d1[i] = deque[begin + i];
	for (i = 0; i < d2Length; ++i)
		d2[i] = deque[mid + 1 + i];

	i = 0;
	j = 0;
	while(i < d1Length && j < d2Length) {
		if (d1[i] <= d2[j])
			deque[dequeIter] = d1[i++];
		else
			deque[dequeIter] = d2[j++];
		++dequeIter;
	}
	while (i < d1Length)
		deque[dequeIter++] = d1[i++];
	while (j < d2Length)
		deque[dequeIter++] = d2[j++];
}

void	PmergeMe::insertionSortD(int begin, int end, std::deque<int> &deque) {
	for (int i = begin; i < end; i++) {
		int j = i + 1;
		int tmp = deque[j];
		while (j > begin && deque[j - 1] > tmp) {
			deque[j] = deque[j - 1];
			--j;
		}
		deque[j] = tmp;
	}
}
