#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
	std::string filename = "data.csv"; // Nom du fichier CSV à lire
	std::ifstream file(filename); // Ouvrir le fichier

	if (!file.is_open()) {
		std::cerr << "Failed to open file " << filename << std::endl;
		return 1;
	}

	std::map<std::string, float> data; // Map pour stocker les données

	std::string line;
	while (std::getline(file, line)) { // Parcourir le fichier ligne par ligne
		std::string date_str;
		float number;

		// Extraire la date et le nombre de la ligne
		std::size_t comma_pos = line.find(',');
		if (comma_pos != std::string::npos) {
			date_str = line.substr(0, comma_pos);
			number = std::stof(line.substr(comma_pos + 1));
		} else {
			std::cerr << "Invalid line format: " << line << std::endl;
			continue;
		}

		// Ajouter la ligne à la map
		data[date_str] = number;
	}

	file.close(); // Fermer le fichier

	return 0;
	// Afficher les données stockées dans la map (pour vérification)
	// for (const auto& [date, number] : data) { //c++11
	// 	std::cout << date << ": " << number << std::endl;
	}



/*Ce code lit le fichier data.csv, extrait la date et le nombre de chaque ligne, et 
les ajoute à une map appelée data avec la date comme clé et le nombre en format float comme valeur. 
Le code affiche ensuite les données stockées dans la map pour vérification.

Adapter ce code selon les besoins en modifiant le nom du fichier CSV, 
la façon dont les données sont stockées dans la map, 
et la façon dont les données sont traitées une fois stockées.*/