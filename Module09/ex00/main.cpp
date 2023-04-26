#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	
	if (argc < 2) {
		std::cerr << "Enter a filename after : " << argv[0] << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string extension = filename.substr(filename.size() - 4);
	if (extension != ".txt") {
		std::cerr << "Invalid file format, must be .txt" << std::endl;
		return 1;
	}

	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cerr << "Failed to open file " << argv[1] << std::endl;
		return 1;
	}

	std::map<string, float> map//container<clef, valeur> nomVariable

	// Lire et traiter les données du fichier ici...

	file.close();
	return 0;
}