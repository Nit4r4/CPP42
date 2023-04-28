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

	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cerr << "Failed to open file " << argv[1] << std::endl;
		return 1;
	}

	try {
		exchange.loadExchangeRates("data.csv");
		exchange.printProductResult();
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}