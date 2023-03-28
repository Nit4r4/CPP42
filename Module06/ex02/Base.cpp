#include "Base.hpp"

Base::~Base(void) {}

Base	*generate(void) {
	int	random;

	srand(time(NULL));
	random = (rand() % 3) + 1;

	switch (random)
	{
		case 1 :
			return (new A);
		case 2 :
			return (new B);
		case 3 :
			return (new C);
		default :
			return (NULL);
	}
}

void	identify(Base* p) {
	if(dynamic_cast<A*>(p)) {
		std::cout << "Identify by pointeur : A" << std::endl;
	}
	else if(dynamic_cast<B*>(p)) {
		std::cout << "Identify by pointeur : B" << std::endl;
	}
	else if(dynamic_cast<C*>(p)) {
		std::cout << "Identify by pointeur : C" << std::endl;
	}
}

// void	identify(Base& p) {
// 	if (A* a = dynamic_cast<A*>(&p)) {
// 		std::cout << "Identify without pointeur : A" << std::endl;
// 	} else if (B* b = dynamic_cast<B*>(&p)) {
// 		std::cout << "Identify without pointeur : B" << std::endl;
// 	} else if (C* c = dynamic_cast<C*>(&p)) {
// 		std::cout << "Identify without pointeur : C" << std::endl;
// 	}
// }

void	identify(Base &p) {
	A	a;
	B	b;
	C	c;

	try {
		a = dynamic_cast<A&>(p);
		std::cout << "Identify without pointeur : A" << std::endl;
	}
	catch (std::exception &bc) {
		//std::cout << "Not a A : " << bc.what() << std::endl;
	}
	try {
		b = dynamic_cast<B&>(p);
		std::cout << "Identify without pointeur : B" << std::endl;
	}
	catch (std::exception &bc) {
		//std::cout << "Not a B : " << bc.what() << std::endl;
	}
	try {
		c = dynamic_cast<C&>(p);
		std::cout << "Identify without pointeur : C" << std::endl;
	}
	catch (std::exception &bc) {
		//std::cout << "Not a C : " << bc.what() << std::endl;       // catch (std::bad_cast) {} allowed ??
	}
}

