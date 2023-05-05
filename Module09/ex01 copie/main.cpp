#include "RPN.hpp"

int	main(int argc, char **argv) {
	RPN rpn;

	if (argc != 2) {
		std::cerr << ERR <<  "Enter a string between double quote on an argument after : " << argv[0] << std::endl;
		return 1;
}

	std::string calcul	= argv[1]; 

	try {
		int result = rpn.postfixEval(calcul);
		if (rpn.getOP() == (rpn.getNum() - 1))
			std::cout << "The result is: " << result << std::endl;
		else
			throw RPN::RPNException("not polish");
	} catch (const std::exception& e) {
		std::cerr << ERR << e.what() << std::endl;
		return 1;
	}

	return 0;
}