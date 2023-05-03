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

	
	// if (calcul != "") //avec un find ??
	// 	throw BtcException("String has to be in  ");
	// while (std::getline(infile, line)) // lire chaque ligne du fichier
	// {
	// 	size_t	found = calcul.find("  ");
	// 	if (found == std::string::npos) {
	// 		if (calcul.empty()) {
	// 			std::cout << ERR << "empty line" << line << std::endl;
	// 			continue;
	// 		}
	// 		else {
	// 			std::cout << ERR << "Bad input => " << line << std::endl;
	// 			continue;
	// 		}
	// 	}

		if (!isdigit(calcul[0])) {
			for(unsigned long i = 0; i < calcul.length(); i++) {
				if (calcul.find("-") != std::string::npos)
					std::cout << ERR << "not all are positive numbers." << std::endl;
			else 
				std::cout << ERR << "not in a string." << std::endl;
			continue;
		}
	}
	
	//rpn.postfixEval(calcul);
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