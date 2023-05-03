#include "RPN.hpp"

RPN::RPN() : _a(0), _b(0) {}

RPN::~RPN() {}

RPN::RPN(const RPN& copy) {
	*this = copy;
}

RPN& RPN::operator=(const RPN& assign) {
	_stack = assign._stack;
	_a = assign._a;
	_b = assign._b;
	return *this;
}

// void	RPN::isAllowedNumber(std::string str) {
// 	for (unsigned long i = 0; i < str.length(); i++) {
// 		if (num < 0 || num > 9) {
// 			std::cout << ERR << "not allowed number(s)." << std::endl;
// 			break;
// 		}
// 	}
// }

int RPN::readNumber(char c) {
	int value;
	value = c;
	return int(value -'0'); //return int from character
}

int RPN::isOperator(char c){
	if(c == '+'|| c == '-'|| c == '*'|| c == '/')
		return 1;//character is an operator
	return -1;//not an operator
}

int RPN::isOperand(char c) {
	if(isdigit(c)) // c >= '0' && c <= '9'
		return 1;//character is an operand
	return -1;//not an operand
}
int RPN::operation(char op) {
	//Perform operation
	if(op == '+')
		return _b + _a;
	else if(op == '-')
		return _b - _a;
	else if(op == '*')
		return _b * _a;
	else if(op == '/')
		return _b / _a;
	else
		return INT_MIN; //return negative infinity
}
int RPN::postfixEval(std::string postfix) {

	std::string::iterator it;
	for (it = postfix.begin(); it != postfix.end(); it++){
		if (isOperator(*it) != -1) {
			_a = _stack.top();
			_stack.pop();
			_b = _stack.top();
			_stack.pop();
			_stack.push(operation(*it));
		}
	else if(isOperand(*it) > 0) {
		_stack.push(readNumber(*it));
		}
	}
	return _stack.top();
}