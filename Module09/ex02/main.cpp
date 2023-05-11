#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	PmergeMe pmm;
	
	if (argc < 2) {
		std::cerr << ERR <<  "Some numbers are expected after : " << argv[0] << std::endl;
		return 1;
	}

	std::vector<int> vect;
	// std::vector<std::pair<int, int> > pairs;

		try {
			for(int i = 1; i < argc; i++) {
			int number = pmm.safeAtoi(argv[i]); //int number = std::stoi(argv[i]); stoi C++11
			vect.push_back(number);
			pmm.setArgNumber(i);
			}
		pmm.evenOddNumArgVect(argc, argv);
		} catch (const std::exception& e) {
			std::cerr << ERR"Argument \e[31m"  << "\e[0mis not a valid number." << std::endl;//<< argv[i]
			return 1;
		}
	
	std::cout << "\n" << std::endl;
	std::cout << "nombre d'argument/nombre : " << pmm.getArgNumber() << std::endl;
	std::cout << std::endl;



std::cout << "Before: " ;
	for (size_t i = 0; i < vect.size(); i++) {
		std::cout << vect[i] << " ";
	}
	std::cout << std::endl;

std::cout << "After: " ;
std::cout << std::endl;
// pmm.swapPairsVector();
pmm.sortNumberAlgo();
// pmm.printResultVector();

// std::cout << "After: " << std::endl;
// std::cout << "Time to process a range of " << pmm.getArgNumber() << "elements with " container << " : " << 0.00031 << " us" << std::endl;
// std::cout << "Time to process a range of " << pmm.getArgNumber() << "elements with " container << " : " << 0.00031 << " us" << std::endl;
}
