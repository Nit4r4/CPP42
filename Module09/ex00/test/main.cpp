#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	BitcoinExchange exchange;
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

	
	//verifier si j ai une data base..... recuperer la data base dans une map
	// std::string fileDB = "data.csv";
	// if (!fileDB.is_open()) {
	// 	std::cerr << "Failed to open file " << fileDB << std::endl;
	// 	return 1;
	// } // mis dans la fonction

	
	
	std::ifstream file(argv[1]); //input.txt
	if (!file.is_open()) {
		std::cerr << "Failed to open file : " << argv[1] << std::endl;
		return 1;
	} // mis dans la fonciton

	std::cout << "RESULTS IN FORMAT :" << std::endl;
	std::cout << "DATE => VALUE = PRODUCT" << std::endl;
	std::cout << "------------------------" << std::endl;
	try {
		exchange.loadExchangeRates();
		exchange.setInputValue(argv[1]);
		//exchange.printProductResult(); // mis dans la fonction
	} catch (const std::exception& e) {
		std::cerr << ERR << e.what() << std::endl;
		return 1;
	}

	return 0;
}