#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream> //ifstream::is_open
# include <string>
# include <algorithm>
# include <sstream>
# include <stdlib.h>

class BitcoinExchange {
	private:
		std::map<std::string, float> _exchangeRates;
		float	_value;
		std::string	_date;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &assign);

		void	loadExchangeRates(void); // charge les données de taux de change à partir d'un fichier CSV
		float	getExchangeRate(const std::string& date) const; // récupère le taux de change pour une date donnée
		float	getInputValue() const; // recuperer les valeurs par date
		void	setInputValue(std::string inputFilename) const; // recuperer les valeurs par date sur map avec parsing
		// float	getInputValue(const std::string& date) const; // recuperer les valeurs par date
		std::string	getInputErrors(std::string& inputFile) const; //recuperer les errors
		void	printProductResult(void); //imprimer sur la sortie standard les resultats et les erreurs ligne par ligne
	//	void	loadData(const std::string& filename);
		bool	isValidDate(std::string _date) const; // verifier que la date est valide

		class BtcException : public std::exception {
		public:
			BtcException(const char* msg) : _msg(msg) {}
			const char* what() const throw() { 
				return _msg;
			}

		private:
			const char* _msg;
		};

};

#endif