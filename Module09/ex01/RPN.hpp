#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <cctype>
# include <iostream>
# include <algorithm>
# include <cmath>
# include <stack>
# include <climits>
#include <stdlib.h>

#define ERR "\e[31mError : \e[0m"
#define RES "\033[32mRESULT : \e[0m"

class	RPN {
	private:
	std::stack<int> _stack; //declaration de la stack
	int	_a; //op1
	int	_b; //op2
	int	_countOP;//compteur d operateur
	int	_countNum; //compteur de chiffre

	public:
		RPN();
		virtual ~RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& assign);

		int getNum();
		int getOP();

		class RPNException : public std::exception {
		public:
			RPNException(const char* msg) : _msg(msg) {}
			const char* what() const throw() { 
				return _msg;
			}

		private:
			const char* _msg;
		};

		//void isAllowedNumber(std::string str);
		int readNumber(char c);
		bool isOperator(char c);
		bool isOperand(char c);
		int operation(char op);
		int postfixEval(std::string postfix);

};

#endif