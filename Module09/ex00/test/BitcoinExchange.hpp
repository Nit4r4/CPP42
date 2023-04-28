#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream> //ifstream::is_open
# include <string>
# include <algorithm>
# include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, float> _exchangeRates;
		float   _value;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &assign);

		void	loadExchangeRates(const std::string& filename); // charge les données de taux de change à partir d'un fichier CSV
		float	getExchangeRate(const std::string& date) const; // récupère le taux de change pour une date donnée
		float	getInputValue() const; // recuperer les valeurs par date
		// float	getInputValue(const std::string& date) const; // recuperer les valeurs par date
		std::string	getInputErrors(const std::string& date) const; //recuperer les errors
		void	printProductResult(void); //imprimer sur la sortie standard les resultats et les erreurs ligne par ligne
		void	loadData(const std::string& filename);

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