#include "Span.hpp"

	int intMain();
	int intMainTest();
	int intMainErr();
	int intMainDixMille();

int	main() {
	intMain();
	intMainTest();
	intMainErr();
	intMainDixMille();
}
int intMain() {

	std::cout << "\nBASIC TESTS :" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortest span : " << sp.shortestSpan() << std::endl; 
	std::cout << "longest span : " << sp.longestSpan() << std::endl;

	return 0;


/* DEVRA AFFICHER CA :
$> ./Span
2
14 
$>
*/
}

int intMainTest() {
	std::cout << "\nOTHER TESTS :" << std::endl;
	Span sp = Span(12);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(10);
	sp.addNumber(23);
	sp.addNumber(657);
	sp.addNumber(32);
	sp.addNumber(54);
	sp.addNumber(123);
	sp.addNumber(0);
	sp.addNumber(111);

	std::cout << "shortest span : " << sp.shortestSpan() << std::endl; 
	std::cout << "longest span : " << sp.longestSpan() << std::endl;

	return 0;


/* DEVRA AFFICHER CA :
$> ./Span
2
657 
$>
*/
}

int	intMainErr() {
	std::cout << "\nERROR TESTS :" << std::endl;
	Span sp = Span(1);

	try {
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(10);
	sp.addNumber(23);
	sp.addNumber(657);
	sp.addNumber(32);
	sp.addNumber(54);
	sp.addNumber(123);
	sp.addNumber(0);
	sp.addNumber(111);
	}
		catch (Span::SpanException &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try {
		std::cout << "shortest span : " << sp.shortestSpan() << std::endl; 
	}
	catch (Span::SpanException &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try {
		std::cout << "longest span : " << sp.longestSpan() << std::endl;
	}
	catch (Span::SpanException &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	return 0;

}

#define BigNum 10000
int	intMainDixMille() {
	std::cout << "\nBIG NUMBERS TEST :" << std::endl;
	Span sp = Span(BigNum);

	std::srand(std::time(nullptr));
	// std::srand(std::time(nullptr) + std::chrono::high_resolution_clock::now().time_since_epoch().count()); // pour lancer l execution plus rapidement et avoir des nombres differents
	for (int i = 0; i < BigNum; i++) {
		int random_number = std::rand() % BigNum;
		sp.addNumber(random_number);
		// std::cout << "\nprint numbers :" << std::endl;
		// std::cout << random_number << std::endl;
	}

	// // Créez un vecteur de nombres uniques et aléatoires mais pas compatible avec C++98 (C++11)
	// std::vector<int> random_numbers(BigNum);
	// std::iota(random_numbers.begin(), random_numbers.end(), 0);
	// std::shuffle(random_numbers.begin(), random_numbers.end(), std::mt19937{std::random_device{}()});

	// // Ajouter des nombres à la classe Span à partir du vecteur de nombres aléatoires
	// Span sp = Span(BigNum);
	// for (int i = 0; i < BigNum; i++) {
	// 	sp.addNumber(random_numbers[i]);
	// }

	try {
		std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
	}
	catch (Span::SpanException &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try {
		std::cout << "longest span : " << sp.longestSpan() << std::endl;
	}
	catch (Span::SpanException &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}

	return 0;
}
