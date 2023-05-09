#include "RPN.hpp"

bool isWhitespaceString(const std::string& str) { //check if string is empty, even if it's all white spaces
	return std::all_of(str.begin(), str.end(), ::isspace);
}

int	main(int argc, char **argv) {
	RPN rpn;

	if (argc != 2) {
		std::cerr << ERR <<  "Enter a string between double quote on an argument after : " << argv[0] << std::endl;
		return 1;
	}

	std::string calcul	= argv[1]; 
	if ( calcul.size() == 0 || isWhitespaceString(calcul)) {
		std::cerr << ERR << "empty string" << std::endl;
		return 1;
	}

	try {
		int result = rpn.postfixEval(calcul);
		if (rpn.getOP() == (rpn.getNum() - 1))
			std::cout << RES << result << std::endl;
		else
			throw RPN::RPNException("not polish notation");
	} catch (const std::exception& e) {
		std::cerr << ERR << e.what() << std::endl;
		return 1;
	}

	return 0;
}