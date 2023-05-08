#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	PmergeMe pmm;
	
	std::vector<int> vect; // besoin de deteriner la taille et le contenu ?
	
	for(int i = 0; i < argc; i++) {
		pmm.setArgNumber(i);
		try {
            int number = std::stoi(argv[i]);
            vect.push_back(number);
			if (!argv[i].isdigit())
				throw PmergeMe::PMMException("Not a digit");
        } catch (const std::exception& e) {
            std::cerr << "Argument " << argv[i] << " is not a valid number." << std::endl;
            return 1;
        }
    }
	
	std::cout << "Before: " << std::endl;
	std::cout << "After: " << std::endl;
	std::cout << "Time to process a range of " << pmm.getArgNumber() << "elements with " container << " : " << 0.00031 << " us" << std::endl;
	std::cout << "Time to process a range of " << pmm.getArgNumber() << "elements with " container << " : " << 0.00031 << " us" << std::endl;
}