#include "PmergeMe.hpp"

// int main(int argc, char **argv) {
// 	PmergeMe pmm;
	
// 		if (argc < 2) {
// 		std::cerr << ERR <<  "Some numbers are expected after : " << argv[0] << std::endl;
// 		return 1;
// 	}

// 	std::vector<int> vect; // besoin de deteriner la taille et le contenu ?
	
// 	for(int i = 0; i < argc; i++) {
// 		pmm.setArgNumber(i);
// 		try {
// 			int number = std::stoi(argv[i]);
// 			vect.push_back(number);
// 			if (!(isdigit(number)))
// 				throw PmergeMe::PMMException("Not a digit");
// 			std::cout << vect << std::endl;
// 		} catch (const std::exception& e) {
// 			std::cerr << "Argument " << argv[i] << " is not a valid number." << std::endl;
// 			return 1;
// 		}
// 	}
	

// 	// std::cout << "Before: " << std::endl;
// 	// std::cout << "After: " << std::endl;
// 	// std::cout << "Time to process a range of " << pmm.getArgNumber() << "elements with " container << " : " << 0.00031 << " us" << std::endl;
// 	// std::cout << "Time to process a range of " << pmm.getArgNumber() << "elements with " container << " : " << 0.00031 << " us" << std::endl;
// }



int main(int argc, char **argv) {
	PmergeMe pmm;
	
	if (argc < 2) {
		std::cerr << ERR <<  "Some numbers are expected after : " << argv[0] << std::endl;
		return 1;
	}

	std::vector<int> vect;
	
	for(int i = 1; i < argc; i++) {
		try {
			int number = std::stoi(argv[i]);
			if (number < 0) {
				std::cerr << ERR << number << " is not a positive number" << std::endl;
				return 1;// throw PmergeMe::PMMException("not positive number(s)");
			}
			vect.push_back(number);
			std::cout << number << " ";
			pmm.setArgNumber(i);
		} catch (const std::exception& e) {
			std::cerr << "Argument " << argv[i] << " is not a valid number." << std::endl;
			return 1;
		}
	}
	std::cout << "\n" << std::endl;
	std::cout << "nombre d'argument/nombre : " << pmm.getArgNumber() << std::endl;
	std::cout << std::endl;

	// Utilisez maintenant le vecteur pour faire autre chose...
}
