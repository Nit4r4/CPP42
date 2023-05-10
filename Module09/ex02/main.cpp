#include "PmergeMe.hpp"

int safeAtoi(const char* str) {
	int result = 0;
	int sign = 1;
	int i = 0;

	// Ignorer les espaces blancs au début de la chaîne
	while (isspace(str[i])) {
		i++;
	}
	// Gérer les signes + ou -
	if (str[i] == '+' || str[i] == '-') {
		if (str[i] == '-') {
			throw PmergeMe::PMMException("not a positive number");
		}
		i++;
	}
	// Vérifier que tous les caractères restants sont des chiffres
	while (isdigit(str[i])) {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	// Si on trouve un caractère non-numérique avant la fin de la chaîne,
	// on retourne 0 pour signaler une erreur.
	if (str[i] != '\0') {
		throw PmergeMe::PMMException("Not a number");
	}
	// Retourner le résultat avec le signe approprié
	return result * sign;
}

// void	printVector() {
// 	std::string vectNumberBefore;
// 	for (int elem : vect) {
// 		vectNumberBefore += std::to_string(elem) + " ";
// 	}
// 	std::cout << vectNumberBefore << std::endl;
// }

int main(int argc, char **argv) {
	PmergeMe pmm;
	
	if (argc < 2) {
		std::cerr << ERR <<  "Some numbers are expected after : " << argv[0] << std::endl;
		return 1;
	}

	std::vector<int> vect;
	std::vector<std::pair<int, int> > pairs;

		try {
			for(int i = 1; i < argc; i++) {
			int number = safeAtoi(argv[i]); //int number = std::stoi(argv[i]); stoi C++11
			// if (number < 0) {
			// 	std::cerr << ERR << number << " is not a positive number" << std::endl;
			// 	return 1;// throw PmergeMe::PMMException("not positive number(s)");
			// }
			vect.push_back(number);
			pmm.setArgNumber(i);
			}
			int argNbr = argc - 1;
			for(int i = 1; i < argNbr; i++) {
			std::cout << " ArgNbr : " << argNbr << std::endl;
			std::cout << " i : " << i << std::endl;
				if (argNbr % 2 == 0) {
					if (i % 2) {
						pairs.push_back(std::make_pair(safeAtoi(argv[i]), safeAtoi(argv[i+1])));//pairs.push_back(std::make_pair(atoi(argv[i]),atoi(argv[i + 2])));
						//std::cout << "pas paires" << std::endl; {
						}
					}
				else {
					if (i == argNbr - 1) {
						std::cout << "joker" << std::endl;
						if (i % 2) {
							std::cout << " ArgNbr moins 1 : " << argNbr - 1 << std::endl;
							std::cout << "JOKER add" << std::endl;
							pairs.push_back(std::make_pair(JOKER, safeAtoi(argv[i])));
						}
						pairs.push_back(std::make_pair(safeAtoi(argv[i]), safeAtoi(argv[i+1])));
					}
				}
				// if (i % 2) {
				// 	if (argNbr % 2 != 0)
				// 	{
				// 		//std::cout << "pas paires" << std::endl;
				// 		if (i % 2 == 0 && i != argNbr) {
				// 			std::cout << "joker" << std::endl;
				// 			pairs.push_back(std::make_pair(JOKER, safeAtoi(argv[i])));
				// 		}
				// 		pairs.push_back(std::make_pair(safeAtoi(argv[i]), safeAtoi(argv[i+1])));
				// 	}
				// 	else 
				// 		pairs.push_back(std::make_pair(safeAtoi(argv[i]), safeAtoi(argv[i+1])));//pairs.push_back(std::make_pair(atoi(argv[i]),atoi(argv[i + 2])));
				// 	// std::cout << "paires : " << safeAtoi(argv[i]) << safeAtoi(argv[i+1]) << " ";
				// }
				
			}
			for(std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
				std::cout << (*it).first << " " << (*it).second << std::endl;
			}
		} catch (const std::exception& e) {
			std::cerr << ERR"Argument \e[31m"  << "\e[0mis not a valid number." << std::endl;//<< argv[i]
			return 1;
		}
	
	std::cout << "\n" << std::endl;
	std::cout << "nombre d'argument/nombre : " << pmm.getArgNumber() << std::endl;
	std::cout << std::endl;

	// Utilisez maintenant le vecteur pour faire autre chose... trier par paire et les paires entre elles
	// puis creer un autre vecteur pour monter les premiers de la paire copier les premier dans le nouveau vecteur
	// -1 JOKER
	// recherche binal


std::cout << "Before: " ;
	for (size_t i = 0; i < vect.size(); i++) {
		std::cout << vect[i] << " ";
	}
	std::cout << std::endl;

std::cout << "After: " ;
pmm.printResultVector();

// std::cout << "After: " << std::endl;
// std::cout << "Time to process a range of " << pmm.getArgNumber() << "elements with " container << " : " << 0.00031 << " us" << std::endl;
// std::cout << "Time to process a range of " << pmm.getArgNumber() << "elements with " container << " : " << 0.00031 << " us" << std::endl;
}
