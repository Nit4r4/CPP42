#include "RPN.hpp"

int	main(int argc, char **argv) {
	RPN rpn;
	// if (argc != 2) {
	// 	throw RPN::RPNException("Too few arguments");
	// }
	if (argc != 2) {
		std::cerr << ERR <<  "Enter a string between double quote on an argument after : " << argv[0] << std::endl;
		return 1;
}

	std::string calcul	= argv[1]; //gerrer les " " ?

	// for(unsigned long i = 0; i < calcul.length(); i++) {
	// 	if (calcul[i] < 0) {
	// 		throw RPN::RPNException("no positive numbers");
	// 	}
	// }

	// for(unsigned long i = 0; i < calcul.length(); i++) {
	// 	if (calcul[i] < 0) {
	// 			std::cout << ERR << "not all numbers are positive." << std::endl;
	// 			break;
	// 	}
	// }

	// for(unsigned long i = 0; i < calcul.length(); i++) {
	// 	if (calcul.find(" - ") != std::string::npos) {
	// 		if (calcul.find("-") != std::string::npos) {
	// 			std::cout << ERR << "not all numbers are positive." << std::endl;
	// 			break;
	// 		}
	// 		else {
	// 			continue;
	// 		}
	// 	}
	// }

	// for(unsigned long i = 0; i < calcul.length(); i++) {
	// 	if (rpn.readNumber(i) < 0)
	// 	std::cerr << ERR << "not all numbers are positive." << std::endl;
	// 	return 0;
	// }


	// for(unsigned long i = 0; i < calcul.length(); i++) {
	// //	if (c == '+'|| c == '-'|| c == '*'|| c == '/') {}
	// 	if (!isdigit(calcul[i])) {
	// 			std::cerr << ERR << "not a digit" << std::endl;
	// 			break;
	// 		}
	// 	else {
	// 		continue;
	// 	}
	// }

	
	//rpn.postfixEval(calcul);
	//rpn.isAllowedNumber(calcul);
	std::cout << rpn.postfixEval(calcul) << std::endl;
	// try {
	// 	rpn.postfixEval(calcul);
	// 	std::cout << "The result is: " << postfixEval(calcul) << std::endl;
	// } catch (const std::exception& e) {
	// 	std::cerr << ERR << e.what() << std::endl;
	// 	return 1;
	// }

	return 0;
}