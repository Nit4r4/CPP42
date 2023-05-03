#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <cmath>
# include <stack>
# include <climits>

#define ERR "\e[31mError : \e[0m"

class	RPN {
	private:
	std::stack<int> _stack; //declaration de la stack
	int	_a; //op1
	int	_b; //op2

	public:
		RPN();
		virtual ~RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& assign);

		class RPNException : public std::exception {
		public:
			RPNException(const char* msg) : _msg(msg) {}
			const char* what() const throw() { 
				return _msg;
			}

		private:
			const char* _msg;
		};

		int readNumber(char c);
		int isOperator(char c);
		int isOperand(char c);
		int operation(char op);
		int postfixEval(std::string postfix);

};

#endif