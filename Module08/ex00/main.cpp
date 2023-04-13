#include "easyfind.hpp"

// void forEachInt(int i) {
// 	std::cout << i << std::endl;
// }

void vector() {
	std::vector<int> v1; //vecteur of integer nameed v1

	v1.push_back(0);
	v1.push_back(17);
	v1.push_back(42);
	v1.push_back(-28);
	std::cout << "VECTOR" << std::endl;
	std::cout << "Le vecteur contient " << v1.size() << " valeur(s).\n";
	for (std::vector<int>::size_type i = 0; i < v1.size(); i++) {
		std::cout << v1[i] << std::endl;
	}

	// std::cout << "\n";
	// std::cout << "Avec la methode for_each : \n";
  	// for_each (v1.begin(), v1.end(), forEachInt);
  	// std::cout << '\n';

	std::cout << "\n";
	int values[] = { 20, 42, -28, -82 };
	int numValues = sizeof(values) / sizeof(values[0]);

	for (int i = 0; i < numValues; i++) {
		try {
			easyfind(v1, values[i]);
			//std::cout << "Element found in the list: " << values[i] << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << values[i] << std::endl;
		}
	}
}

void list() {
	std::list<int> lst1; //list of integer nameed v1

	lst1.push_back(0);
	lst1.push_back(17);
	lst1.push_back(42);
	lst1.push_back(-28);
	std::cout << "\nLIST" << std::endl;
	std::cout << "La liste contient " << lst1.size() << " valeur(s).\n";
	for (std::list<int>::iterator it = lst1.begin(); it != lst1.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "\n";
	
	int values[] = { 20, 42, -28, -82 };
	int numValues = sizeof(values) / sizeof(values[0]);

	for (int i = 0; i < numValues; i++) {
		try {
			easyfind(lst1, values[i]);
			//std::cout << "Element found in the list: " << values[i] << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << values[i] << std::endl;
		}
	}

	// try {
	// 	easyfind(lst1, 20);
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// try {
	// 	easyfind(lst1, 42);
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// try {
	// 	easyfind(lst1, -28);
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
	// try {
	// 	easyfind(lst1, -82);
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;
	// }
}

int main() {
	vector();
	std::cout << "-----------------------------------------" << std::endl;
	list();
	// #ifdef _WIN32
	// system("pause");
	// #else
	// std::cout << "Press enter to continue..." << std::endl;
	// std::cin.get();
	// #endif
	return 0;
}