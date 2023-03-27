#include "convert.hpp"


convert::convert() : _int(0), _char('\0'), _float(0.0f), _double(0.0) {}

convert::~convert(void) {}

convert::convert(const convert &copy) {
	*this = copy;
}

convert	&convert::operator = (const convert &assign) {
	if (this == &assign)
		return *this;
	this->setInt(assign.getInt());
	this->setChar(assign.getChar());
	this->setFloat(assign.getFloat());
	this->setDouble(assign.getDouble());
	return *this;
}

bool	convert::isStringNan(char *str) {
	std::string	argc;
	size_t		i = 0;
	bool		dot = false;

	argc = static_cast<std::string>(str);
	if (argc == "nan" || argc == "nanf")
		return true;
	else {
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i]) {
			if (str[i] == '.') {
				if (dot)
					return true;
				dot = true;
			}
			else if (str[i] == 'f' && i == (argc.length() - 1)) {
				return false;
			}
			else if (!isdigit(str[i]))
				return true;
			i++;
		}
	}
	return false;
}

bool	convert::isStringInf(char *str) {
	std::string	arg;

	arg = static_cast<std::string>(str);
	if (arg == "+inff" || arg == "-inff" || arg == "+inf" || arg == "-inf")
		return true;
	return false;
}

void	convert::stringFnull(char *str) {
	int	i = 0;

	while (i < (int)strlen(str) - 1)
		i++;
	if (str[i] == 'f')
		str[i] = '\0';
}

int		convert::stringToChar(void) {
	if (!(this->getInt() >= 32 && this->getInt() <= 127))
		return (1);
	else
		this->setChar(this->getInt());
	return 0;
}

int		convert::stringToInt(char *str) {
	// Vérification si c'est un char
	if (strlen(str) == 1 && isItChar(str[0]) == true) {
		int ascii = static_cast<int>(str[0]);
		this->setInt(ascii);
		return 0;
	}

	// Sinon, c'est un nombre
	long num;
	std::istringstream(str) >> num;

	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min()) {
		return -1;
	}
	else {
		num = 0;
		int okNum = std::stoi(str);
		this->setInt(okNum);
	}
	return 0;
}

int		convert::stringToFloat(char *str) {
	// Vérification si c'est un char
	if (strlen(str) == 1 && isItChar(str[0]) == true) {
		int ascii = static_cast<float>(str[0]);
		this->setFloat(ascii);
		return 0;
	}

	// Sinon, c'est un nombre
	float num;
	std::istringstream(str) >> num;
	int decimalPlaces = decAfterDot(str); // calcul du nombre de décimales

	if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min()) {
		return -1;
	}
	else {
		num = 0;
		float okNum = std::stof(str);
		this->setFloat(okNum);
		std::cout << "float: " << std::fixed << std::setprecision(decimalPlaces) << okNum << "f" << std::endl; // Affichage du nombre avec le nombre de décimales approprié

	}
	return 0;
}

int		convert::stringToDouble(char *str) {
	// Vérification si c'est un char
	if (strlen(str) == 1 && isItChar(str[0]) == true) {
		int ascii = static_cast<double>(str[0]);
		this->setDouble(ascii);
		return 0;
	}

	// Sinon, c'est un nombre
	double num;
	std::istringstream(str) >> num;

	int decimalPlaces = decAfterDot(str); // calcul du nombre de décimales

	if (num > std::numeric_limits<double>::max() || num < std::numeric_limits<double>::min()) {
		return -1;
	}
	else {
		num = 0;
		double okNum = std::stod(str);
		this->setDouble(okNum);
		std::cout << "double: " << std::fixed << std::setprecision(decimalPlaces) << okNum << std::endl; // Affichage du nombre avec le nombre de décimales approprié
	}
	return 0;
}

void	convert::setChar(char newChar) {
	this->_char = newChar;
}

void	convert::setInt(int newInt) {
	this->_int = newInt;
}

void	convert::setFloat(float newFloat) {
	this->_float = newFloat;
}

void	convert::setDouble(double newDouble) {
	this->_double = newDouble;
}

char	convert::getChar(void) const {
	return this->_char;
}

int		convert::getInt(void) const {
	return this->_int;
}

float	convert::getFloat(void) const {
	return this->_float;
}

double	convert::getDouble(void) const {
	return this->_double;
}

int decAfterDot(std::string argv) {
	int i = 0;
	int j = 0;

	while (argv[i] != '\0' && argv[i] != '.')
			i++;
	if (argv[i] == '\0')
		return 0;
	while (argv[i] != '\0') {
		if (argv[i] == 'f')
			j--;
		j++;
		i++;
	}
	j--;
	return (j);
}

bool isItChar(char c) {
	if (isprint(c) && !isnumber(c))
		return true;
	else
		return false;
}

// bool isItChar(char c) {
//     if (isprint(c) && !isdigit(c)) {
//         int ascii = static_cast<int>(c);
//         std::cout << "'" << c << "'" << std::endl;
//         std::cout << "int: " << ascii << std::endl;
//         return true;
//     }
//     else {
//         std::cout << "Non-printable character detected." << std::endl;
//         return false;
//     }
// }