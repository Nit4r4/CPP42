#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream> //ifstream::is_open
# include <string>
# include <algorithm>

class BitcoinExchange {
	private:
		float	_value;
		std::map<std::string, float> _exchangeRates;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &assign);

		void	setData(float product); // calculer le produit tdc * value = product
		float	getData(void) const; //recuperer le taux de change et les valeur

		//gestion d erreur try and catch pour le fichierde comparaison entré en parametre lors de la compilation (input)
		// class MyException : public std::exception {
		// 	virtual const char *what() const throw();
		// };
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