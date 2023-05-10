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

// int	PmergeMe::getArgNumber(const int number) const {
// 	std::vector<int>::const_iterator it = _vect.find(number);
// 	if (it == _vect.end()) {
// 		throw PmergeMe::PMMException("Number not found in vector");
// 	}
// 	return it->second;
// }

void	PmergeMe::sortNumberAlgo(int i) {
	std::vector<std::pair<int, int> > pairs;
	std::pair <int,int> pr;

	pr = std::make_pair(_vect[i], _vect[i + 1]);
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

// void	jokerProcess() {
// 	std::sort(_pairs.begin(), _pairs.end());
// 	std::vector< std::pair<int, int> >::iterator it=_pairs.begin();
// 	if ((*it).first == -1)
// 	{
// 		_pairs.insert(_pairs.end(), _pairs.front());
// 		_pairs.erase(_pairs.begin());
// 	}
// }

void	PmergeMe::upFirstOfPairsVector()
{
	for (std::vector< std::pair<int, int> >::iterator it=_pairs.begin(); it != _pairs.end(); it++)
	{
		if ((*it).first == JOKER)
			continue;
		_sortVect.push_back((*it).first);
	}
}

void	PmergeMe::printResultVector()
{
	for (std::vector<int>::iterator it=_sortVect.begin(); it != _sortVect.end(); it++)
	{
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}