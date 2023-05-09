#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _countArgNumber(0) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& assign) {
	_countArgNumber = assign._countArgNumber;
	return *this;
}

int	PmergeMe::getArgNumber() {
	return _countArgNumber;
}

void	PmergeMe::setArgNumber(int argNum) {
	_countArgNumber = argNum;
}

void	sortNumberAlgo() {

}

int		PmergeMe::timeToProcessRange() {

   // Prendre le temps de début
	clock_t start = clock();

	// Exécuter l'algorithme de tri
	// ...

	// Prendre le temps de fin
	clock_t end = clock();

	// Calculer le temps écoulé en secondes
	double elapsed_time = double(end - start) / CLOCKS_PER_SEC;

	std::cout << "Temps écoulé: " << elapsed_time << " secondes" << std::endl;

	return elapsed_time;
}
