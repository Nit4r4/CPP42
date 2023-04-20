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

	std::cout << sp.shortestSpan() << std::endl; 
	std::cout << sp.longestSpan() << std::endl;

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

	std::cout << sp.shortestSpan() << std::endl; 
	std::cout << sp.longestSpan() << std::endl;

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
		std::cout << sp.shortestSpan() << std::endl; 
	}
	catch (Span::SpanException &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	try {
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (Span::SpanException &e) {
		std::cerr << "Error : " << e.what() << std::endl;
	}
	return 0;

}

int	intMainDixMille() {
	
}
