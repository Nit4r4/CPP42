
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _exchangeRates(), _value(0) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &assign){
	_value = assign._value;
	_exchangeRates = assign._exchangeRates;
	
	return *this;
}

void BitcoinExchange::loadExchangeRates(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw BtcException("Error: could not open file. ");
	}

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date;
		float rate;
		if (!(iss >> date >> rate)) {
			throw BtcException("Invalid input line");
		}
		_exchangeRates[date] = rate;
	}
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
	std::map<std::string, float>::const_iterator it = _exchangeRates.find(date);
	if (it == _exchangeRates.end()) {
		throw BtcException("Date not found in exchange rates");
	}
	return it->second;
}

float BitcoinExchange::getInputValue() const {
	return _value;
}
// float BitcoinExchange::getInputValue(const std::string& date) const {
// 	return _value;
// }

std::string BitcoinExchange::getInputErrors(const std::string& date) const {
	try {
		getExchangeRate(date);
		return ""; // no error
	} catch(const std::exception& e) {
		return e.what();
	}
}

void BitcoinExchange::printProductResult(void) {
	std::cout << "Product result:" << std::endl;
	std::cout << "---------------" << std::endl;

	std::ifstream inputFile("input.txt");
	std::ofstream outputFile("output.txt");

	std::string line;
	while (std::getline(inputFile, line)) {
		std::istringstream iss(line);
		std::string date, amountStr;
		float amount = 0.0;
		if (!(iss >> date >> amountStr)) {
			std::cerr << "Invalid input line: " << line << std::endl;
			continue;
		}
		try {
			float rate = getExchangeRate(date);
			float result = amount * rate;
			outputFile << date << " " << result << std::endl;
			std::cout << date << " " << result << std::endl;
		} catch(const std::exception& e) {
			outputFile << date << " " << e.what() << std::endl;
			std::cerr << date << " " << e.what() << std::endl;
		}
	}

	inputFile.close();
	outputFile.close();
}

void BitcoinExchange::loadData(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		throw BtcException("Failed to open file");
	}

	std::string line;
	std::getline(file, line); // ignore header line

	std::map<std::string, float> exchangeRates;

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string dateStr, rateStr;

		std::getline(ss, dateStr, ',');
		std::getline(ss, rateStr, ',');

		float rate = std::atof(rateStr.c_str());
		exchangeRates[dateStr] = rate;
	}

	file.close();
}
