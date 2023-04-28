#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	
	if (argc < 2) {
		std::cerr << "Enter a filename after : " << argv[0] << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string extension = filename.substr(filename.size() - 4);
	if (extension != ".txt") {
		std::cerr << "Invalid file format, must be .txt" << std::endl;
		return 1;
	}

	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cerr << "Failed to open file " << argv[1] << std::endl;
		return 1;
	}

	std::map<string, float> map;//container<clef, valeur> nomVariable
	std::map<std::string, std::vector<float> > data; // Stocke les données par date


	// Lire et traiter les données du fichier ici...

	try {
			//quelque chose avec le input.
		}
	catch (BitcoinExchange::BtcException &e) {
		std::cerr << "Error : too large number." << e.what() << std::endl;
	}
		try {
			//quelque chose
		}
	catch (BitcoinExchange::BtcException &e) {
		std::cerr << "Error: bad input => 2001-42-42" << e.what() << std::endl;
	}	try {
			//quelque chose
		}
	catch (BitcoinExchange::BtcException &e) {
		std::cerr << "Error : not a positive number." << e.what() << std::endl;
	}

	file.close();
	return 0;
}






// TEST //
/*Dans ce code, la boucle while lit chaque ligne du fichier avec la fonction getline. 
Si la ligne est vide, une erreur est affichée et la boucle continue à la ligne suivante. 
Si la ligne contient des données, elle est analysée en utilisant la classe std::stringstream. 
La première partie de la ligne (avant la virgule) est considérée comme une chaîne de caractères représentant la date. 
La deuxième partie de la ligne (après la virgule) est convertie en un nombre flottant à l'aide de la fonction std::stof. 
Si la valeur est en dehors de la plage 0-1000, une exception BitcoinExchange::BtcException est lancée et
*/

#include "BitcoinExchange.hpp"
#include <sstream> // std::stringstream

int	main(int argc, char **argv) {
	
	if (argc < 2) {
		std::cerr << "Enter a filename after : " << argv[0] << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string extension = filename.substr(filename.size() - 4);
	if (extension != ".txt") {
		std::cerr << "Invalid file format, must be .txt" << std::endl;
		return 1;
	}

	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cerr << "Failed to open file " << argv[1] << std::endl;
		return 1;
	}

	std::map<std::string, std::vector<float> > data; // Stocke les données par date

	std::string line;
	int line_num = 0;
	while (std::getline(file, line)) {
		line_num++;
		if (line.empty()) {
			std::cerr << "Error: line " << line_num << " is empty." << std::endl;
			continue;
		}

		std::stringstream ss(line);
		std::string date_str;
		float value;

		if (!std::getline(ss, date_str, ',')) {
			std::cerr << "Error: line " << line_num << " is missing date." << std::endl;
			continue;
		}

		try {
			value = std::stof(ss.str().substr(ss.tellg()));
			if (value < 0 || value > 1000) {
				throw BitcoinExchange::BtcException("Error: value out of range (0-1000).");
			}
		}
		catch (std::invalid_argument&) {
			std::cerr << "Error: line " << line_num << " has invalid value." << std::endl;
			continue;
		}
		catch (std::out_of_range&) {
			std::cerr << "Error: line " << line_num << " has value out of range." << std::endl;
			continue;
		}
		catch (BitcoinExchange::BtcException& e) {
			std::cerr << e.what() << " (line " << line_num << ")" << std::endl;
			continue;
		}

		// Stocke les données dans la map
		data[date_str].push_back(value);
	}

	file.close();

	// Traitement des données stockées dans la map

	return 0;
}


//iterateur pour parcourir les deux map et ecrire le resultat de la multiplication sur la sortie standard


// Parcourir la map du fichier CSV
for (auto const& data : csv_data) {
    std::string date = data.first;
    float csv_value = data.second;

    // Rechercher la date correspondante dans la map du fichier input.txt
    auto input_data = input.find(date);
    if (input_data != input.end()) {
        // Si la date correspond, multiplier les valeurs associées et les afficher sur la sortie standard
        float input_value = input_data->second;
        float result = csv_value * input_value;
        std::cout << date << "," << result << std::endl;
    }
}


/*Ici, csv_data est la map que vous avez créée à partir du fichier CSV et input est la map que vous avez créée à partir du fichier input.txt. La boucle parcourt chaque élément de la map csv_data, qui contient une date et une valeur float. Pour chaque élément de csv_data, la boucle recherche la date correspondante dans la map input. Si la date correspond, les valeurs associées sont multipliées et affichées sur la sortie standard.

Notez que si vous avez besoin de comparer des dates, il peut être utile d'utiliser une bibliothèque de date et d'heure, telle que Boost.Date_Time ou Chrono.*/