#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _value(0), _exchangeRates(0) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &assign){
	_value = assign._value;
	_exchangeRates = assign._exchangeRates;
	
	return *this;
}

// void BitcoinExchange::loadExchangeRates(const std::string& filename)
// {
// 	filename = "data.csv";
// 	std::ifstream infile(filename);
// 	if (!infile.is_open()) {
// 		throw BtcException("Failed to open file");
// 	}

// 	std::string line;
// 	// Skip the header row
// 	std::getline(infile, line);

// 	while (std::getline(infile, line)) {
// 		std::stringstream ss(line);
// 		std::string date;
// 		float rate;

// 		if (std::getline(ss, date, ',') && ss >> rate) {
// 			_exchangeRates[date] = rate;
// 		} else {
// 			throw BtcException("Failed to parse line");
// 		}
// 	}

// 	infile.close();
// }

// float BitcoinExchange::getExchangeRate(const std::string& date) const
// {
// 	float	it = _exchangeRates.find(date);
// 	if (it == _exchangeRates.end()) {
// 		throw BtcException("Date not found");
// 	}

// 	return _exchangeRates;
// }

	void loadExchangeRates(const std::string& filename) {
		std::ifstream file(filename.c_str());
		if (!file.is_open()) {
			throw BtcException("Unable to open file");
		}

		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string date;
			float rate;
			if (!(iss >> date >> rate)) {
				throw BtcException("Invalid input line");
			}
			exchangeRates.insert(std::make_pair(date, rate));
		}
	}


  float getExchangeRate(const std::string& date) const {
			_exchangeRates::const_iterator it = _exchangeRates.find(date);
			if (it == _exchangeRates.end()) {
				throw BtcException("Date not found in exchange rates");
			}
			return it->second;
		}


float	getInputValue(const std::string& date) const {

	return _value;
}

std::string	getInputErrors(const std::string& date) const {
	try
	{
		/* code */
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

void BitcoinExchange::loadData(const std::string& filename)
{
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

	// update the class member variable with the loaded exchange rates
	_exchangeRates = exchangeRates;
}
