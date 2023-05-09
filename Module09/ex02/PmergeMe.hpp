#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <ctime>

#define ERR "\e[31mError : \e[0m"
#define RES "\033[32mRESULT : \e[0m"

class PmergeMe {
	private:
		unsigned long int	_countArgNumber;
		std::vector<int> _vect;
		std::list<int> _list;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& assign);

		int		getArgNumber();
		void	setArgNumber(int argNum);
		void	sortNumberAlgo();
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