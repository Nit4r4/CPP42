
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
	std::string fileDB = "data.csv";
	if (!fileDB.is_open()) {
		throw BtcException("Error: could not open file. ");
	}
	std::string line;
	std::getline(file, line); // ignore header line


	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string dateStr, rateStr;

		std::getline(ss, dateStr, ',');
		std::getline(ss, rateStr, ',');

		float rate = std::atof(rateStr.c_str());
		_exchangeRates[dateStr] = rate;
	}
	file.close();
	for(std::map<std::string, float>::iterator it = _exchangeRates.begin(); it != _exchangeRates.end(); it++)
	{
		std::cout << (*it).first << " | " << (*it).second << std::endl;
	}
}


float BitcoinExchange::getExchangeRate(const std::string& date) const {
	std::map<std::string, float>::const_iterator it = _exchangeRates.find(date);
	if (it == _exchangeRates.end()) {
		throw BtcException("Date not found in exchange rates");
	}
	return it->second;
}

void	BitcoinExchange::setInputValue(std::string inputFilename) const {
	std::map<std::string, float> _value; // map dont les clés sont les dates et les valeurs sont des flottants
	std::ifstream infile(inputFilename);
	std::string line;

	while (std::getline(infile, line)) // lire chaque ligne du fichier
	{
		std::string date_str;
		float value;

		std::istringstream iss(line); // utiliser un stringstream pour extraire les valeurs de la ligne
		iss >> date_str;
		iss.ignore(); // ignorer le caractère '|' ou espace
		iss >> value;

		_value[date_str] += value; // ajouter la valeur à la somme associée à la date dans le map
	}

	// parcourir le map et afficher les valeurs pour chaque date
	for (std::map<std::string, float>::iterator it = _value.begin(); it != _value.end(); ++it)
	{
		std::cout << "Date: " << it->first << std::endl;
		std::cout << "Value: " << it->second << std::endl;
	}
}

bool	BitcoinExchange::isValidDate(std::string _date) const {
	//std::string format;
	int	year;
	// int	month;
	// int	day;

	year = atoi(_date.substr(0, 4).c_str()); //annee
	std::cout << year << std::endl;

	//format = 1000 a 3000 || 1 a 12 || 1 a 31 lire et comparer ????
	return true;
}

float BitcoinExchange::getInputValue() const {
	return _value;
}
// float BitcoinExchange::getInputValue(const std::string& date) const {
// 	return _value;
// }

// std::string BitcoinExchange::getInputErrors(std::string& inputFile) const {
// 	try {
// 			if(_value < 1000 && _value > 0)
// 				BitcoinExchange::setInputValue(inputFile);
// 		}
// 	catch (BitcoinExchange::BtcException &e) {
// 		std::cerr << "Error : too large number." << e.what() << std::endl;
// 	}
// 		try {
// 			if(_value < 1000 && _value > 0)
// 				BitcoinExchange::setInputValue(inputFile);		}
// 	catch (BitcoinExchange::BtcException &e) {
// 		std::cerr << "Error: bad input => 2001-42-42" << e.what() << std::endl;
// 	}	try {
// 			BitcoinExchange::setInputValue(inputFile);
// 			if (_value >= 0) 
// 		}
// 	catch (BitcoinExchange::BtcException &e) {
// 		std::cerr << "Error : not a positive number." << e.what() << std::endl;
// 	}
// // try {
// // 		getExchangeRate(date);
// // 		return ""; // no error
// // 	} catch(const std::exception& e) {
// // 		return e.what();
// // 	}
// }

std::string BitcoinExchange::getInputErrors(std::string& inputFile) const {
	try {
		// Récupérer la valeur de l'input
		BitcoinExchange::setInputValue(inputFile);

		// Vérifier que la valeur est positive et inférieure à 1000
		if (_value <= 0) {
			throw BitcoinExchange::BtcException("not a positive number.");
		}
		if (_value >= 1000) {
			throw BitcoinExchange::BtcException("too large number.");
		}

		// Vérifier que la date est valide
		if (!BitcoinExchange::isValidDate(_date)) {
			throw BitcoinExchange::BtcException("invalid date.");
		}

		// Si aucune erreur n'a été levée, retourner une chaîne vide
		return ""; // le resultat de la somme
	}
	catch (BitcoinExchange::BtcException &e) {
		// En cas d'erreur, retourner un message d'erreur contenant la description de l'erreur
		std::string errorMessage = "Error: ";
		if (_date.empty() || _date == "2001-42-42") {
			errorMessage += "bad input => 2001-42-42.";
		}
		else {
			errorMessage += e.what();
		}
		return errorMessage;
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
