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
	// 	if (_countOP >= _countNum) {
	// 		std::cerr << ERR << "not all numbers are positive." << std::endl;
	// 		break;
	// 	}
	// }

/* pas plus de deux chiffres consecutifs */
// si il y a plus d operateur que d operand c est faux
//la division par zero est impossible

	// for(unsigned long i = 0; i < calcul.length(); i++) { //si tout ok on commence sinon erreurs 
	// 	// if (c == '+'|| c == '-'|| c == '*'|| c == '/') {}
	// 	if (rpn.isOperator(calcul[i])) {
	// 		if (rpn.isOperand(i)) {
	// 			std::cout << rpn.postfixEval(calcul) << std::endl;
	// 			continue;
	// 		}
	// 		else {
	// 			std::cerr << ERR << "operator not conforme" << std::endl;
	// 			break;
	// 		}
	// 	}
	// 	else {
	// 		std::cerr << ERR << "not a positive digit" << std::endl;
	// 		break;
	// 	}
	// 	std::cerr << ERR << "nike ta grosse daronne" << std::endl;
	// 	break;
	// }

	
	try {
		int result = rpn.postfixEval(calcul);
		if (result != 3)
			std::cout << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}



	//rpn.postfixEval(calcul);
	//rpn.isAllowedNumber(calcul);
	//std::cout << rpn.postfixEval(calcul) << std::endl;
	// try {
	// 	rpn.postfixEval(calcul);
	// 	std::cout << "The result is: " << postfixEval(calcul) << std::endl;
	// } catch (const std::exception& e) {
	// 	std::cerr << ERR << e.what() << std::endl;
	// 	return 1;
	// }

	return 0;
}