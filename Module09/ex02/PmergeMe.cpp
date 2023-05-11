#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _countArgNumber(0) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) {
	*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& assign) {
	_countArgNumber = assign._countArgNumber;
	_vect = assign._vect;
	_pairs = assign._pairs;
	_sortVect = assign._sortVect;
	_list = assign._list;
	return *this;
}

int	PmergeMe::getArgNumber() {
	return _countArgNumber;
}

void	PmergeMe::setArgNumber(int argNum) {
	_countArgNumber = argNum;
}

void	PmergeMe::evenOddNumArgVect(int argc, char **argv) {
	int argNbr = argc - 1;
	for(int i = 1; i < argNbr; i++) {
		if (argNbr % 2 == 0) {
			if (i % 2) {
				_pairs.push_back(std::make_pair(PmergeMe::safeAtoi(argv[i]), PmergeMe::safeAtoi(argv[i+1])));//_pairs.push_back(std::make_pair(atoi(argv[i]),atoi(argv[i + 2])));
				}
			}
		else {
				if (i % 2) {
					_pairs.push_back(std::make_pair(PmergeMe::safeAtoi(argv[i]), PmergeMe::safeAtoi(argv[i+1])));
				}
			if (i == argNbr - 1) {
				_pairs.push_back(std::make_pair(JOKER, PmergeMe::safeAtoi(argv[i + 1])));
			}
		}
	}
	for(std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); it++) {
		std::cout << (*it).first << " " << (*it).second << std::endl;
	}
	// PmergeMe::swapPairsVector();
	// PmergeMe::upFirstOfPairsVector();
}


void PmergeMe::insertionSortVect(std::vector<std::pair<int, int> >& pairs, std::vector<int>& sortVect) {
	for (std::vector<std::pair<int, int> >::const_iterator itPair = pairs.begin(); itPair != pairs.end(); ++itPair) {
		int num = itPair->second;
		std::vector<int>::iterator it = std::upper_bound(sortVect.begin(), sortVect.end(), num);
		sortVect.insert(it, num);
	}
}

void	PmergeMe::sortNumberAlgo() {

	PmergeMe::swapPairsVector();
	PmergeMe::upFirstOfPairsVector();
		// Affichage du résultat
//   Parcourir le vecteur et imprimer chaque paire
	for (std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it) {
		std::cout << "Vecteur _paires trier : " << it->first << it->second << std::endl;
	}

	std::cout << "\nBefore sort compare : " << std::endl;
	for (size_t i = 0; i < _sortVect.size(); i++) {
		std::cout << _sortVect[i] << " ";
	}

	PmergeMe::insertionSortVect(_pairs, _sortVect);

	std::cout << "\nAfter sort : " << std::endl;
	for (size_t i = 0; i < _sortVect.size(); i++) {
		std::cout << _sortVect[i] << " ";
	}
// for (std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it) {
// 	for (size_t i = 0; i < _pairs.size(); i++) {
// 		if (std::binary_search (_sortVect.begin(), _sortVect.end(), _pairs[i])) {
// 			std::cout << _pairs[i].first << " " << _pairs[i].second << " ";
// 		}
// 	}
// }


	// 	// Tri du vecteur _sortVect
	// std::sort(_sortVect.begin(), _sortVect.end());

	// // Insérer chaque élément de _sortVect dans vec1
	// for (size_t i = 0; i < _sortVect.size(); i++) {
	// 	std::vector<int>::iterator it = std::lower_bound(_pairs.begin(), _pairs.end(), _sortVect[i]);
	// 	_pairs.insert(it, _sortVect[i]);
	// }

	// // Affichage du résultat
	// for (size_t i = 0; i < _pairs.size(); i++) {
	// 	std::cout << _pairs[i] << " ";
	// }
	// std::cout << std::endl;
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


void	PmergeMe::swapPairsVector()
{
	int	rig;

	for (std::vector< std::pair<int, int> >::iterator it=_pairs.begin(); it != _pairs.end(); it++)
	{
		if ((*it).first > (*it).second) //(*it).first it's the 1st number of the pair
		{
			rig = (*it).first;
			(*it).first = (*it).second; //(*it).second it's the 2nd number of the pair
			(*it).second = rig;
		}
	}
	std::sort(_pairs.begin(), _pairs.end());
	std::vector< std::pair<int, int> >::iterator it=_pairs.begin();// a enlever ?
	if ((*it).first == JOKER)
	{
		_pairs.insert(_pairs.end(), _pairs.front());
		_pairs.erase(_pairs.begin());
	}
}

void	PmergeMe::upFirstOfPairsVector() {
	for (std::vector< std::pair<int, int> >::iterator it=_pairs.begin(); it != _pairs.end(); it++)
	{
		if ((*it).first == JOKER)
			continue;
		_sortVect.push_back((*it).first);
	}
}

void	PmergeMe::printResultVector() {
	for (std::vector<int>::iterator it=_sortVect.begin(); it != _sortVect.end(); it++)
	{
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}

