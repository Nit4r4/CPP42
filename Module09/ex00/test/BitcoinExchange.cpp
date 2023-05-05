
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

void BitcoinExchange::loadExchangeRates(void) {
	std::ifstream fileDB("data.csv");
	if (!fileDB.is_open()) {
		throw BtcException("Error: could not open file. ");
	}
	std::string line;
	std::getline(fileDB, line); // ignore header line


	while (std::getline(fileDB, line))
	{
		std::stringstream ss(line);
		std::string dateStr, rateStr;

		std::getline(ss, dateStr, ',');
		std::getline(ss, rateStr, ',');

		float rate = std::atof(rateStr.c_str());
		_exchangeRates[dateStr] = rate;
	}
	fileDB.close();
	// verification de la map :
	// for(std::map<std::string, float>::iterator it = _exchangeRates.begin(); it != _exchangeRates.end(); it++)
	// {
	// 	std::cout << (*it).first << " | " << (*it).second << std::endl;
	// }
}


float BitcoinExchange::getExchangeRate(const std::string& date) const {
	std::map<std::string, float>::const_iterator it = _exchangeRates.find(date);
	if (it == _exchangeRates.end()) {
		throw BtcException("Date not found in exchange rates");
	}
	return it->second;
}

void	BitcoinExchange::setInputValue(std::string inputFile) {
	// std::map<std::string, float> _value; // map dont les clés sont les dates et les valeurs sont des flottants
	std::ifstream infile(inputFile);
	std::string line;

	// if (!infile.is_open()) {
	// 	std::cerr << "Failed to open file : " << inputFile << std::endl;
	// 	return ;
	// }
	std::getline(infile, line);
	if (line != "date | value")
		throw BtcException("Wrong header in file.");
	while (std::getline(infile, line)) // lire chaque ligne du fichier
	{
		size_t	found = line.find(" | ");
		if (line.size() < 14 || found == std::string::npos) {
			if (line.empty()) {
				std::cout << ERR << "Bad input => empty line" << line << std::endl;
				continue;
			}
			else {
				std::cout << ERR << "Bad input => " << line << std::endl;
				continue;
			}
		}
		// if (line.empty()) {
		// 	std::cout << ERR << "Bad input => empty line" << line << std::endl;
		// 	continue;
		// }
		if (!isdigit(line[13])) {
			if (line[13] == '-')
				std::cout << ERR << "not a positive number." << std::endl;
			else 
				std::cout << ERR << "not a number." << std::endl;
			continue;
		}
		_value = atof(line.substr(13).c_str()); //float value at 13td place
		if (_value > 1000) {
			std::cout << ERR << "too large number." << std::endl;
			continue;
		}
		// Vérifier que la date est valide
		if (!isValidDate(line)) {
			std::cout << ERR << "Bad input => " << _year << "-" << _month << "-" << _day << std::endl;
			continue;
		}
		//std::cout << "value : " << _value << std::endl;
		printProductResult(line);
	// parcourir le map et afficher les valeurs pour chaque date
	// for (std::map<std::string, float>::iterator it = _value.begin(); it != _value.end(); ++it)
	// {
	// 	std::cout << "Date: " << it->first << std::endl;
	// 	std::cout << "Value: " << it->second << std::endl;
	// }
	}
}

bool	BitcoinExchange::isValidDate(std::string line) {

	if ((line.substr(4, 1) == "-") && (line.substr(7, 1) == "-")) {

		_year = atoi(line.substr(0, 4).c_str()); //annee
		//std::cout << _year << std::endl;

		_month = atoi(line.substr(5, 2).c_str()); //mois
		//std::cout << _month <<std::endl;

		_day = atoi(line.substr(8, 2).c_str()); //jour
		//std::cout << _day <<std::endl;

		if (_year > 1000 && _year < 3000) {
			if (_month >= 1 && _month <= 12) {
				if (_day <= 31 && _day >= 1) {
					return true;
				}
			}
		}
	}
	return false;
}

float BitcoinExchange::getInputValue() const {
	return _value;
}


// void BitcoinExchange::printProductResult(void) {
// 	std::cout << "Product result:" << std::endl;
// 	std::cout << "---------------" << std::endl;

// 	std::ifstream inputFile("input.txt");
// 	//std::ofstream outputFile("output.txt");

// 	std::string line;
// 	while (std::getline(inputFile, line)) {
// 		std::istringstream iss(line);
// 		std::string date, amountStr;
// 		float amount = 0.0;
// 		if (!(iss >> date >> amountStr)) {
// 			std::cerr << "Invalid input line: " << line << std::endl;
// 			continue;
// 		}
// 		try {
// 			float rate = getExchangeRate(date);
// 			float result = amount * rate;
// 			outputFile << date << " " << result << std::endl;
// 			std::cout << date << " " << result << std::endl;
// 		} catch(const std::exception& e) {
// 			outputFile << date << " " << e.what() << std::endl;
// 			std::cerr << date << " " << e.what() << std::endl;
// 		}
// 	}

// 	inputFile.close();
// 	outputFile.close();
// }


void BitcoinExchange::printProductResult(std::string line) {
	//fonction qui compare chaque ligne et compare les dates et si les dates sont ok multiplie et imprime sur la sortie standard.
	std::string inputFileDates;

	inputFileDates = line.substr(0, 10); //donc les 9 premiers caracteres

	std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(inputFileDates);
	if ((it->first > inputFileDates) || it == _exchangeRates.end()) {// ca signifie quoi ?
		if ((it) != _exchangeRates.begin()) {
			it--;
			std::cout << inputFileDates << " => " << _value << " = " << (it->second * _value) << std::endl;
		}
		else
			std::cout << ERR << "“La route ? Là où on va, on n'a pas besoin de route !”" << std::endl;
	}
	else
		std::cout << inputFileDates << " => " << _value << " = " << (it->second * _value) << std::endl;
}