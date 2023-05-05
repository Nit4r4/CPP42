// #include "BitcoinExchange.hpp"

// bool isEmptyFile(std::string inputFile) {
// 	std::ifstream is(inputFile, std::ifstream::binary);
// 	if (is) {
// 		// get length of file:
// 		is.seekg(0, is.end);
// 		int length = is.tellg();
// 		is.seekg(0, is.beg);

// 		// check if file is empty
// 		if (length == 0) {
// 			//std::cerr << "File : " << inputFile << " is empty" << std::endl;
// 			return true;
// 		}
// 	}
// 	return false;
// }

// int main(int argc, char **argv) {
// 	BitcoinExchange exchange;
// 	if (argc < 2) {
// 		std::cerr << "Enter a filename after : " << argv[0] << std::endl;
// 		return 1;
// 	}

// 	// std::string filename = argv[1];
// 	// std::string extension = filename.substr(filename.size() - 4);
// 	// if (extension != ".txt" && extension != ".csv") {
// 	// 	std::cerr << "Invalid file format" << std::endl;
// 	// 	return 1;
// 	// }

// 	// std::string line = argv[1];
// 	// size_t	found = line.find(".");
// 	// if (found != std::string::npos) {
// 	// 	std::string extension = line.substr(line.size() - 4);
// 	// 	if (extension != ".txt" && extension != ".csv") {
// 	// 		std::cerr << "Invalid file format entered" << std::endl;
// 	// 		return 1;
// 	// 	}
// 	// 	else {
// 	// 		std::cerr << "No file found" << std::endl;
// 	// 		return 1;
// 	// 	}
// 	// }

// 	std::ifstream file(argv[1]); //input.txt
// 	if (!file.is_open()) {
// 		std::cerr << "Failed to open file : " << argv[1] << std::endl;
// 		return 1;
// 	}

// 	std::string filename = argv[1];
// 	if (isEmptyFile(filename)) {
// 		std::cerr << "File : " << filename << " is empty" << std::endl;
// 		return 1;
// 	}

// 	std::cout << "RESULTS IN FORMAT :" << std::endl;
// 	std::cout << "DATE => VALUE = PRODUCT" << std::endl;
// 	std::cout << "------------------------" << std::endl;
// 	try {
// 		exchange.loadExchangeRates();
// 		exchange.setInputValue(argv[1]);
// 	} catch (const std::exception& e) {
// 		std::cerr << ERR << e.what() << std::endl;
// 		return 1;
// 	}
// 	return 0;
// }

#include "BitcoinExchange.hpp"

bool isEmptyFile(std::string inputFile) {
	std::ifstream is(inputFile, std::ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		// check if file is empty
		if (length == 0) {
			//std::cerr << "File : " << inputFile << " is empty" << std::endl;
			return true;
		}
	}
	return false;
}

int main(int argc, char **argv) {
	BitcoinExchange exchange;
	if (argc < 2) {
		std::cerr << "Enter a filename after : " << argv[0] << std::endl;
		return 1;
	}

	std::string line = argv[1];
	size_t	foundT = line.find(".txt");
	size_t	foundC = line.find(".csv");
	if (foundT == std::string::npos && foundC == std::string::npos) {
			std::cerr << "Invalid file format entered" << std::endl;
			return 1;
		}


	std::ifstream file(argv[1]); //input.txt
	if (!file.is_open()) {
		std::cerr << "Failed to open file : " << argv[1] << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	if (isEmptyFile(filename)) {
		std::cerr << "File : " << filename << " is empty" << std::endl;
		return 1;
	}

	std::cout << "RESULTS IN FORMAT :" << std::endl;
	std::cout << "DATE => VALUE = PRODUCT" << std::endl;
	std::cout << "------------------------" << std::endl;
	try {
		exchange.loadExchangeRates();
		exchange.setInputValue(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << ERR << e.what() << std::endl;
		return 1;
	}
	return 0;
}