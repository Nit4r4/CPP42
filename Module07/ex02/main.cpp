#include "Array.tpp"
#include "Array.hpp"

template <typename T>
const char	*Array<T>::MyException::what(void) const throw() {
	return ("Invalid acces");
}

int intMain();
int intMainOut();
int floatMain();
void copyMain();

int main()
{
	intMain();
	intMainOut();
	copyMain();
	floatMain();
}

#define MAX_VAL_IN 10
int intMain() {
	std::cout << "\nINT VALUE IN" << std::endl; //in range tests
	Array<int> numbers(MAX_VAL_IN);
	int* mirror = new int[MAX_VAL_IN];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL_IN; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << "\nint before :" << std::endl;
	std::cout << "numbers = " << numbers[1] << std::endl;
	std::cout << "mirror = " << mirror[1] << std::endl;

	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL_IN; i++) {
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "\nint after :" << std::endl;
	try {
		numbers[3] = 0;//in range
		std::cout << numbers[3] << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "Error : " << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL_IN - 1] = 0;//in range
		std::cout << numbers[MAX_VAL_IN - 1] << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "Error : " << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL_IN; i++) {
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}


#define MAX_VAL_OUT 750
int intMainOut() {
	std::cout << "\nINT VALUE OUT" << std::endl;
	Array<int> numbers(MAX_VAL_OUT);
	int* mirror = new int[MAX_VAL_OUT];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL_OUT; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL_OUT; i++) {
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try {
		numbers[-2] = 0;//out of range
	}
	catch(const std::exception& e) {
		std::cerr << "Error : " << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL_OUT] = 0;//out of range
	}
	catch(const std::exception& e) {
		std::cerr << "Error : " << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL_OUT; i++) {
		numbers[i] = rand();
	}
	delete [] mirror;//
	return 0;
}

#define MAX_VAL 5
void copyMain() {
	std::cout << "\nINT VALUE CHECK COPY" << std::endl;
	int *a = new int();
	int* mirror = new int[MAX_VAL];
	Array<int> numbers(MAX_VAL);
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
		a[i] = value;
		// std::cout << mirror[i] << std::endl;
		// std::cout << numbers[i] << std::endl;
		// std::cout << a[i] << std::endl;
		std::cout << "[numbers : " << numbers[i] << "] == ["\
		<< "a : " << a[i] << "] == ["\
		<< "mirror : " << mirror[i] << "]" << std::endl;
	}
	std::cout << std::endl;
	{

	}
	delete a;
	delete [] mirror;
}

//to erase before push
// #define MAX_VAL 5
// void copyMain() {
// 	std::cout << "\nINT VALUE CHECK COPY" << std::endl;
// 	int *a = new int();
// 	int* mirror = new int[MAX_VAL];
// 	Array<int> numbers(MAX_VAL);
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 		std::cout << mirror[i] << std::endl;
// 	}
// 	std::cout << std::endl;
// 	{
// 		Array<int> copy;
// 		copy = numbers;
// 		for (int i = 0; i < MAX_VAL; i++)
// 		{
// 			std::cout << copy[i] << " == " << numbers[i] << std::endl;
// 		}
// 	}
// 	std::cout << std::endl;
// 	{
// 		Array<int> copy = numbers;
// 		for (int i = 0; i < MAX_VAL; i++)
// 		{
// 			std::cout << copy[i] << " == " << numbers[i] << std::endl;
// 		}
// 	}
// 	delete a;
// 	delete [] mirror;
// }

#define MAX_VAL_F 100
int floatMain() {
	std::cout << "\nWITH FLOAT VALUE" << std::endl;
	Array<float> numbers(MAX_VAL_F);
	float* mirror = new float[MAX_VAL_F];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL_F; i++) {
		const float value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
		std::cout << "floats : " << std::endl;
		std::cout << "numbers[1] : " << numbers[1] << std::endl;
		std::cout << "mirror [1] : " << mirror[1] << std::endl;

	{
		Array<float> tmp = numbers;
		Array<float> test(tmp);
	}

	std::cout << "\ntests : " << std::endl;

	for (int i = 0; i < MAX_VAL_F; i++) {
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try {
		numbers[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << "Error : " << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL_F] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << "Error : " << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL_F; i++) {
		numbers[i] = rand();
	}
	delete [] mirror;
	return 0;
}