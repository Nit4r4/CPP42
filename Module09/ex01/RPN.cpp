#include "RPN.hpp"

RPN::RPN() : _a(0), _b(0), _countOP(0), _countNum(0) {}

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

bool RPN::isOperator(char c){
	if(c == '+'|| c == '-'|| c == '*'|| c == '/') {
		_countOP++;
		return true;//character is an operator
	}
	return false;//not an operator
}

bool RPN::isOperand(char c) {
	if(isdigit(c)) { // c >= '0' && c <= '9'
		_countNum++;
		return true;//character is an operand
	}
	return false;//not an operand
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




// int RPN::postfixEval(std::string postfix) {
// 	std::string::iterator it;
// 	for (it = postfix.begin(); it != postfix.end(); it++) {
// 		if (isOperator(*it)) {
// 			if (_countOP >= _countNum) {
// 				throw RPNException(ERR"not all characters are allowed.");
// 			}
// 			_a = _stack.top();
// 			_stack.pop();
// 			_b = _stack.top();
// 			_stack.pop();
// 			_stack.push(operation(*it));
// 		} else if (isOperand(*it)) {
// 			_stack.push(readNumber(*it));
// 		} else {
// 			throw RPNException(ERR"invalid character.");
// 		}
// 	}
// 	return _stack.top();
// }



int RPN::postfixEval(std::string postfix) {

	std::string::iterator it;
	for (it = postfix.begin(); it != postfix.end(); it++){
		if (isOperator(*it) != false) {
			if (_countOP >= _countNum) {
			std::cerr << ERR << "not all characters are allowed." << std::endl;//std::cerr << ERR << "not all number are positives." << std::endl; ou throw RPNException(ERR"not all characters are allowed.");
			return 3;
		}
			_a = _stack.top();
			_stack.pop();
			_b = _stack.top();
			_stack.pop();
			_stack.push(operation(*it));
		}
	else if (isOperand(*it) != false) {
		_stack.push(readNumber(*it));
		}
	}
	return _stack.top();
}

		// if (isOperand(*it) != false && isOperator(*it) != true) {
		// 	std::cerr << ERR << "character " << *it << " not allowed." << std::endl;
		// 	break;
		// }