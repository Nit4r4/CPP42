#include "data.hpp"

int	main() {
	
	Data	ui;
	Data	*ptr;

	uintptr_t	uiptr;

std::cout << "SERIALIZATION / DESERIALIZATION\n " << std::endl;
std::cout << "***** TEST WITH 42 ***** \n" << std::endl;

	ui.setData(42);
	
	std::cout << "Data before serialize : " << ui.getData() << std::endl;

	ptr = &ui;

	std::cout << "Poiteur adress before cast : " << ptr << std::endl;

	uiptr = serialize(&ui);

	std::cout << "Data after serialize : " << ui.getData() << std::endl;

	ptr = deserialize(uiptr);

	std::cout << "Data after deserialize : " << ptr->getData() << std::endl;

	std::cout << "Poiteur adress after cast : " << ptr << std::endl;

std::cout << "\n " << std::endl;
std::cout << "***** TEST WITH 0 *****\n " << std::endl;

	ui.setData(0);
	
	std::cout << "Data before serialize : " << ui.getData() << std::endl;

	ptr = &ui;

	std::cout << "Poiteur adress before cast : " << ptr << std::endl;

	uiptr = serialize(&ui);

	std::cout << "Data after serialize : " << ui.getData() << std::endl;

	ptr = deserialize(uiptr);

	std::cout << "Data after deserialize : " << ptr->getData() << std::endl;

	std::cout << "Poiteur adress after cast : " << ptr << std::endl;


std::cout << "\n " << std::endl;
std::cout << "***** TEST WITH UINT_MAX *****\n " << std::endl;

	ui.setData(UINT_MAX);
	
	std::cout << "Data before serialize : " << ui.getData() << std::endl;

	ptr = &ui;

	std::cout << "Poiteur adress before cast : " << ptr << std::endl;

	uiptr = serialize(&ui);

	std::cout << "Data after serialize : " << ui.getData() << std::endl;

	ptr = deserialize(uiptr);

	std::cout << "Data after deserialize : " << ptr->getData() << std::endl;

	std::cout << "Poiteur adress after cast : " << ptr << std::endl;


	//delete ptr;
	return 0;
}