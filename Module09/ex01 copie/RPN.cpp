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
	_countNum = assign._countNum;
	_countOP = assign._countOP;
	return *this;
}


int RPN::getNum() {
	return _countNum;
}

int RPN::getOP() {
	return _countOP;
}

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

int RPN::postfixEval(std::string postfix) {

	std::string::iterator it;
	
	for (it = postfix.begin(); it != postfix.end(); it++) {
		if (isOperand(*it) != false) {
				_stack.push(readNumber(*it));
		}
		else if (isOperator(*it) != false) {
			if (_stack.empty()) {
				throw RPN::RPNException("1 Not enough operands for operator.");
			}
			_a = _stack.top();
			if (_stack.size() < 2 || _countNum < 2)
				throw RPN::RPNException("Not enough operands or operators.");
			_stack.pop();
			_b = _stack.top();
			_stack.pop();
			_stack.push(operation(*it));
		}
		else if (isspace(*it)) {
			continue;
		}
		else {
			throw RPN::RPNException("Character not allowed");
		}
	}
	return _stack.top();
}
