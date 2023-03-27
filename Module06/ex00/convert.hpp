#ifndef CONVERT_HPP
# define CONVERT_HPP

# define RED "\e[31m"
# define RESET "\e[0m"

# include <iostream>
# include <string>
# include <sstream>
# include <limits>
# include <cctype>
# include <iomanip>

class convert {
	private:
		int		_int;
		char	_char;
		float	_float;
		double	_double;

	public:
		convert();
		~convert();
		convert(const convert &copy);
		convert	&operator = (const convert &assign);

		bool	isStringNan(char *str); //**
		bool	isStringInf(char *str); //**
		void	stringFnull(char *str);

		int		stringToChar(void);
		int		stringToInt(char *str);
		int		stringToFloat(char *str);
		int		stringToDouble(char *str);

		void	setChar(char newChar);
		void	setInt(int newInt);
		void	setFloat(float newFloat);
		void	setDouble(double newDouble);

		char	getChar(void) const;
		int		getInt(void) const;
		float	getFloat(void) const;
		double	getDouble(void) const;
};

int decAfterDot(std::string argv);
bool isItChar(char c);

#endif

/* 

-inf, +inf et nan sont des constantes littérales en C++ 
qui représentent respectivement l'infini négatif, l'infini positif 
et la valeur NaN (Not a Number) pour les nombres à virgule de type double.

-inff, +inff et nanf sont des constantes littérales en C++ 
qui représentent respectivement l'infini négatif, l'infini positif 
et la valeur NaN (Not a Number) pour les nombres à virgule flottante de type float.

*/