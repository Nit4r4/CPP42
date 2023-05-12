#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <ctime>
# include <climits> //UNSIGNED_INT_MAX
# include <stdlib.h>
# include <algorithm>
# include <iterator>

#define START "\033[32m"
#define END "\e[0m"
#define ERR "\e[31mError : \e[0m"
#define RES "\033[32mRESULT : \e[0m"
#define JOKER -1

class PmergeMe {
	private:
		unsigned long int	_countArgNumber;
		clock_t	_vTime;
		clock_t	_lTime;
		std::vector<int> _vect;
		std::vector<std::pair<int, int> > _pairs;
		std::vector<int> _sortVect;
		std::list<std::pair<int, int> > _pairList;
		std::list<int> _sortList;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& assign);

		/* VECTOR */
		void	swapPairsVector();
		void	upFirstOfPairsVector();
		void	evenOddNumArgVect(int argc, char **argv); //impaires
		void	insertionSortVect(std::vector<std::pair<int, int> >& pairs, std::vector<int>& sortVect);
		void	sortNumberAlgo();
		void	printResultVector();

		/* LIST */
		void	swapPairsList();
		void	upFirstOfPairsList();
		void	evenOddNumArgList(int argc, char **argv); //impaires
		void	insertionSortList(std::list<std::pair<int, int> >& pairs, std::list<int>& sortVect);
		void	sortNumberAlgoList();
		void	printResultList();

		/* UTILS */
		clock_t	getVectTime();
		clock_t	getListTime();
		int		getArgNumber();
		void	setArgNumber(int argNum);
		int		safeAtoi(const char* str);

		class PMMException : public std::exception {
			public:
				PMMException(const char* msg) : _msg(msg) {}
				const char* what() const throw() { 
					return _msg;
				}

			private:
				const char* _msg;
		};
};


#endif