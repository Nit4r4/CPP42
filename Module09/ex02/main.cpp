#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	PmergeMe pmm;
	
	/* CHECK ARGS ERRORS */
	if (argc < 2) {
		std::cerr << ERR <<  "Some numbers are expected after : " << argv[0] << std::endl;
		return 1;
	}

try {
	for (int i = 1; i < pmm.safeAtoi(argv[1]); i++) {
		int	coucou = pmm.safeAtoi(argv[1]);
		if (coucou < 0 ) {
			std::cerr << ERR << "NOP " << std::endl;
			return 1;
		}
		break;
	}
	} catch (const std::exception& e) {
			std::cerr << ERR"Not allowed caracter or number." << std::endl;//<< argv[i]
			return 1;
	}

	if (argc < 3) {
		std::cerr << ERR <<  "More numbers are expected after : " << argv[1] << std::endl;
		return 1;
	}

	/* CHECK ARGS ERRORS AND FILL THE CONTAINERS */
	int ErrArgIndex = 0;
	std::vector<int> vect;
		try {
			for(int i = 1; i < argc; i++) {
			int number = pmm.safeAtoi(argv[i]);
			vect.push_back(number);
			pmm.setArgNumber(i);
			}
		pmm.evenOddNumArgVect(argc, argv);
		pmm.evenOddNumArgList(argc, argv);
		} catch (const std::exception& e) {
				ErrArgIndex = pmm.getArgNumber();
			if (ErrArgIndex > 0) {
				std::cerr << ERR"Argument \e[31m" << argv[ErrArgIndex + 1] << " \e[0mis not a valid number" << e.what() << std::endl;//<< argv[i]
				return 1;
			}
		}

	/* PRINT RESULTS MESSAGES ON THE STANDARD OUTPUT */
std::cout << "Before: " ;
	for (size_t i = 0; i < vect.size(); i++) {
		std::cout << vect[i] << " ";
	}

/*VECTOR RESULT*/
pmm.sortNumberAlgo();
pmm.printResultVector();

/*LIST RESULT*/
pmm.sortNumberAlgoList();
pmm.printResultList();

std::cout << "Time to process a range of "START << pmm.getArgNumber() << END" elements with std::vector<int> vector; : "START << pmm.getVectTime() << END" us" << std::endl;
std::cout << "Time to process a range of "START << pmm.getArgNumber() << END" elements with std::list<int> list; : "START << pmm.getListTime() << END" us" << std::endl;
}
