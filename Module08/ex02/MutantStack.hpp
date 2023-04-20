#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <deque>
# include <stdlib.h>
# include <list>
# include <stack>
# include <vector>


// class MutantStack {
// 	public:
// 		MutantStack();
// 		~MutantStack();
// 		MutantStack(const MutantStack& copy);
// 		MutantStack& operator=(const MutantStack& assign);

// 	private:
// };

// #if 1
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& assign) 
	{
		this->c = assign.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() { 
		return this->c.begin(); 
		}
	iterator end() { 
		return this->c.end(); 
		}
};

#endif