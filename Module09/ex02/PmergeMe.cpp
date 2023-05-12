#include "PmergeMe.hpp"

/* Orthodox Canonical Form */

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
	_pairList = assign._pairList;
	_sortList = assign._sortList;
	return *this;
}

/* UTILS */

int PmergeMe::safeAtoi(const char* str) {
	long result = 0;
	int sign = 1;
	int i = 0;

	// Ignorer les espaces blancs au début de la chaîne
	while (isspace(str[i])) {
		i++;
	}

	// Gérer les signes + ou -
	if (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-') {
			throw PmergeMe::PMMException(" --> not a positive number");
		}
		i++;
	}
	// Vérifier que tous les caractères restants sont des chiffres
	while (isdigit(str[i])) {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	// Si on trouve un caractère non-numérique avant la fin de la chaîne,
	// on retourne 0 pour signaler une erreur.
	if (str[i] != '\0') {
		throw PmergeMe::PMMException(" --> not a number");
	}
	//gestion des int max
	if (result >= INT_MAX) {
		throw PmergeMe::PMMException(" --> MAX INT overpassed");
	}
	// Retourner le résultat avec le signe approprié
	return result * sign;
}

int	PmergeMe::getArgNumber() {
	return _countArgNumber;
}

void	PmergeMe::setArgNumber(int argNum) {
	_countArgNumber = argNum;
}

clock_t	PmergeMe::getVectTime() {
	clock_t ms = 1000000/CLOCKS_PER_SEC;
	return _vTime * ms;
}

clock_t	PmergeMe::getListTime() {
	clock_t ms = 1000000/CLOCKS_PER_SEC;
	return _lTime * ms;
}

/* VECTOR FUNCTIONS */

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
	// for(std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); it++) {
	// 	std::cout << (*it).first << " " << (*it).second << std::endl;
	// }
	// PmergeMe::swapPairsVector();
	// PmergeMe::upFirstOfPairsVector();
}


void PmergeMe::insertionSortVect(std::vector<std::pair<int, int> >& pairs, std::vector<int>& sortVect) {
	for (std::vector<std::pair<int, int> >::const_iterator itPair = pairs.begin(); itPair != pairs.end(); ++itPair) {
		int num = itPair->second; //(*itPair).second;
		std::vector<int>::iterator it = std::upper_bound(sortVect.begin(), sortVect.end(), num);
		sortVect.insert(it, num);
	}
}

void	PmergeMe::sortNumberAlgo() {
	_vTime = clock();
	PmergeMe::swapPairsVector();
	PmergeMe::upFirstOfPairsVector();
		// Affichage du résultat
//   Parcourir le vecteur et imprimer chaque paire
	// for (std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it) {
	// 	std::cout << "Vecteur _paires trier : " << it->first << it->second << std::endl;
	// }

	// std::cout << "\nBefore sort compare : " << std::endl;
	// for (size_t i = 0; i < _sortVect.size(); i++) {
	// 	std::cout << _sortVect[i] << " ";
	// }

	PmergeMe::insertionSortVect(_pairs, _sortVect);
	_vTime = clock() - _vTime;
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
	std::vector< std::pair<int, int> >::iterator it=_pairs.begin();
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
	std::cout << "\nAfter (VECTOR):" << " ";
	for (size_t i = 0; i < _sortVect.size(); i++) {
		std::cout << _sortVect[i] << " ";
	}
	std::cout << std::endl;
}

/* LIST FUNCTIONS */

void	PmergeMe::evenOddNumArgList(int argc, char **argv) {
	int argNbr = argc - 1;
	for(int i = 1; i < argNbr; i++) {
		if (argNbr % 2 == 0) {
			if (i % 2) {
				_pairList.push_back(std::make_pair(PmergeMe::safeAtoi(argv[i]), PmergeMe::safeAtoi(argv[i+1])));//_pairs.push_back(std::make_pair(atoi(argv[i]),atoi(argv[i + 2])));
				}
			}
		else {
				if (i % 2) {
					_pairList.push_back(std::make_pair(PmergeMe::safeAtoi(argv[i]), PmergeMe::safeAtoi(argv[i+1])));
				}
			if (i == argNbr - 1) {
				_pairList.push_back(std::make_pair(JOKER, PmergeMe::safeAtoi(argv[i + 1])));
			}
		}
	}
}

// void PmergeMe::evenOddNumArgList(int argc, char **argv) {
// 	int argNbr = argc - 1;
// 	if (argNbr % 2 == 0) {
// 		for (int i = 1; i < argNbr; i += 2) {
// 			_pairList.push_back(std::make_pair(PmergeMe::safeAtoi(argv[i]), PmergeMe::safeAtoi(argv[i+1])));
// 		}
// 	} else {
// 		for (int i = 1; i < argNbr - 1; i += 2) {
// 			_pairList.push_back(std::make_pair(PmergeMe::safeAtoi(argv[i]), PmergeMe::safeAtoi(argv[i+1])));
// 		}
// 		_pairList.push_back(std::make_pair(JOKER, PmergeMe::safeAtoi(argv[argNbr])));
// 	}
// }


void PmergeMe::insertionSortList(std::list<std::pair<int, int> >& pairs, std::list<int>& sortList) {
	for (std::list<std::pair<int, int> >::const_iterator itPair = pairs.begin(); itPair != pairs.end(); ++itPair) {
		int num = itPair->second; //(*itPair).second;
		std::list<int>::iterator it = std::upper_bound(sortList.begin(), sortList.end(), num);
		sortList.insert(it, num);
	}
}

void	PmergeMe::sortNumberAlgoList() {
	_lTime = clock();
	PmergeMe::swapPairsList();
	PmergeMe::upFirstOfPairsList();
	PmergeMe::insertionSortList(_pairList, _sortList);
	_lTime = clock() - _lTime;
}

void	PmergeMe::swapPairsList()
{
	int	rig;
	for (std::list< std::pair<int, int> >::iterator it = _pairList.begin(); it != _pairList.end(); it++)
	{
		if ((*it).first > (*it).second) //(*it).first it's the 1st number of the pair
		{
			rig = (*it).first;
			(*it).first = (*it).second; //(*it).second it's the 2nd number of the pair
			(*it).second = rig;
		}
	}
	_pairList.sort();
	// std::sort(_pairList.begin(), _pairList.end());
	std::list< std::pair<int, int> >::iterator it = _pairList.begin();
	if ((*it).first == JOKER)
	{
		_pairList.insert(_pairList.end(), _pairList.front());
		_pairList.erase(_pairList.begin());
	}
}

void	PmergeMe::upFirstOfPairsList() {
	for (std::list< std::pair<int, int> >::iterator it=_pairList.begin(); it != _pairList.end(); it++)
	{
		if ((*it).first == JOKER)
			continue;
		_sortList.push_back((*it).first);
	}
}

void	PmergeMe::printResultList() {
	std::cout << "After (LIST):" << " ";
	for (std::list<int>::iterator it=_sortList.begin(); it != _sortList.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}