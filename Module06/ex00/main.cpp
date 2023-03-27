
#include "convert.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << RED "Error : bad arguments" RESET << std::endl;
		return 1;
	}

	convert	c;

	if (strlen(argv[1]) == 1 && isItChar(argv[1][0]) == true) {
		//if (!c.stringToChar())
			std::cout << "char: " << argv[1][0] << std::endl;
		if (!c.stringToInt(argv[1]))
			std::cout << "int: " << c.getInt() << std::endl;
		if (!c.stringToFloat(argv[1]))
			std::cout << "float: " << c.getFloat() << ".0f" << std::endl;
		if (!c.stringToDouble(argv[1]))
			std::cout << "double: " << c.getDouble() << ".0" << std::endl;
	}

	else {
		if (c.isStringInf(argv[1])) {
			std::cout << "char: no conversion possible" << std::endl << "int: no conversion possible" << std::endl;
			if (argv[1][0] == '+')
				std::cout << "float: +inff" << std::endl << "double: +inf" << std::endl;
			else
				std::cout << "float: -inff" << std::endl << "double: -inf" << std::endl;
			return 0;
		}
		else if (c.isStringNan(argv[1])) {
			std::cout << "char: no conversion possible" << std::endl << "int: no conversion possible" << std::endl 
				<< "float: nanf" << std::endl << "double: nan" << std::endl;
			return 0;
		}
		c.stringFnull(argv[1]);
		if (c.stringToInt(argv[1])) {
			std::cout << "char: not printable" << std::endl << "int: not printable" << std::endl;
		}
		else {
			if (c.stringToChar()) {
				std::cout << "char: not printable" << std::endl << "int: " << c.getInt() << std::endl;
			}
			else {
				std::cout << "char: '" << c.getChar() << "'" << std::endl << "int: " << c.getInt() << std::endl;
			}
		}

		if (c.stringToFloat(argv[1])) {
			std::cout << "float: not printable" << std::endl;
		}

		if (c.stringToDouble(argv[1])) {
			std::cout << "double: not printable" << std::endl;
		}

		return 0;
	}
	
}

// int main() {
// 	std::string str = "1";
// 	int num = std::stoi(str);
// 	float fnum = std::stof(str);
// 	double dnum = std::stod(str);
// 	//double cnum = str;
// 	std::stringstream ss;
// 	ss << str;
// 	std::string myString = ss.str();
//    // std::cout << "La chaîne " << str << " en char num est " << cnum << std::endl;
//     std::cout << "La chaîne " << str << " en char est " << myString << std::endl;
// 	std::cout << "La chaîne " << str << " en int est " << num << std::endl;
// 	std::cout << "La chaîne " << str << " en float est " << fnum << "f" << std::endl;
// 	std::cout << "La chaîne " << str << " en  double " << dnum << std::endl;
// 	return 0;
// }

/* La principale différence entre float et double est leur précision et leur taille de stockage. 
Le type float : est stocké sur 4 octets (32 bits) et peut représenter des nombres avec une précision d'environ 6 à 7 chiffres significatifs, 
Le type double : est stocké sur 8 octets (64 bits) et peut représenter des nombres avec une précision d'environ 15 à 16 chiffres significatifs.*/