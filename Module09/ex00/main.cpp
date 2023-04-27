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

	std::map<string, float> map;//container<clef, valeur> nomVariable

	// Lire et traiter les données du fichier ici...

	try {
			//quelque chose
		}
	catch (BitcoinExchange::BtcException &e) {
		std::cerr << "Error : too large number." << e.what() << std::endl;
	}
		try {
			//quelque chose
		}
	catch (BitcoinExchange::BtcException &e) {
		std::cerr << "Error: bad input => 2001-42-42" << e.what() << std::endl;
	}	try {
			//quelque chose
		}
	catch (BitcoinExchange::BtcException &e) {
		std::cerr << "Error : not a positive number." << e.what() << std::endl;
	}

	file.close();
	return 0;
}