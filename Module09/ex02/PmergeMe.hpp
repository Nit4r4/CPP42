#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <ctime>
# include <stdlib.h>

#define ERR "\e[31mError : \e[0m"
#define RES "\033[32mRESULT : \e[0m"
#define JOKER -1

class PmergeMe {
	private:
		unsigned long int	_countArgNumber;
		std::vector<int> _vect;
		std::vector<int> _sortVect;
		std::list<int> _list;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& assign);

		int		getArgNumber();
		void	setArgNumber(int argNum);
		//int		getArgNumber(const std::string& number) const;
		void	sortNumberAlgo(int i);
		int		timeToProcessRange();
		
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