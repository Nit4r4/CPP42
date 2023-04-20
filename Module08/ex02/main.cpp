#include "MutantStack.hpp"

int	mainSubjectMutant();
int	mainSubjectList();
int	mainCont();

int	main() {
	mainSubjectMutant();
	mainSubjectList();
	mainCont();
}

int mainSubjectMutant() {
	std::cout << "\nTEST MAIN SUBJECT WITH MUTANT (lol): " << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(42);

	std::cout << "Last number entered : " << mstack.top() << std::endl;
	mstack.pop(); // remove last one
	std::cout << "Size of Stack : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	std::cout << " \nNumbers still on the stack + added : " << std::endl;

	while (it != ite) {
		std::cout << *it << std::endl;
	++it;
	}

	std::stack<int> s(mstack); //s pour stack

	return 0;
}

int mainSubjectList() {
	std::cout << "\nTEST MAIN SUBJECT WITH LIST : " << std::endl;
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);
	mstack.push_back(42);

	std::cout << "Top number of the list : " << mstack.front() << std::endl;//instead of .top
	std::cout << "Last number entered : " << mstack.back() << std::endl;//instead of .top
	mstack.pop_back(); // remove last one
	std::cout << "Size of Stack : " << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;

	std::cout << " \nNumbers still on the stack + added : " << std::endl;

	while (it != ite) {
		std::cout << *it << std::endl;
	++it;
	}

	return 0;
}

int mainCont() {
	std::cout << "\nMORE TEST MAIN : " << std::endl;
	// if (argc != 2)
	// {
	// 	std::cerr << "Usage: ./X seed" << std::endl;
	// 	std::cerr << "Provide a seed please" << std::endl;
	// 	std::cerr << "Count value:" << COUNT << std::endl;
	// 	return 1;
	// }
	// const int seed = atoi(argv[1]);
	// srand(seed);

	// ft::vector<std::string> vector_str;
	// ft::vector<int> vector_int;
	// ft::stack<int> stack_int;
	// ft::vector<Buffer> vector_buffer;
	// ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	// ft::map<int, int> map_int;

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	vector_buffer.push_back(Buffer());
	// }

	// for (int i = 0; i < COUNT; i++)
	// {
	// 	const int idx = rand() % COUNT;
	// 	vector_buffer[idx].idx = 5;
	// }
	// ft::vector<Buffer>().swap(vector_buffer);

	// try
	// {
	// 	for (int i = 0; i < COUNT; i++)
	// 	{
	// 		const int idx = rand() % COUNT;
	// 		vector_buffer.at(idx);
	// 		std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	//NORMAL ! :P
	// }
	
	// for (int i = 0; i < COUNT; ++i)
	// {
	// 	map_int.insert(ft::make_pair(rand(), rand()));
	// }

	// int sum = 0;
	// for (int i = 0; i < 10000; i++)
	// {
	// 	int access = rand();
	// 	sum += map_int[access];
	// }
	// std::cout << "should be constant with the same seed: " << sum << std::endl;

	// {
	// 	ft::map<int, int> copy = map_int;
	// }
	// MutantStack<char> iterable_stack;
	// for (char letter = 'a'; letter <= 'z'; letter++)
	// 	iterable_stack.push(letter);
	// for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	// {
	// 	std::cout << *it;
	// }
	// std::cout << std::endl;

	MutantStack<int> mstack;
	if (mstack.empty())
		std::cout << "Empty Stack" << std::endl;

	mstack.push(5);
	mstack.push(17);
	mstack.push(42);

	std::cout << "Last number entered : " << mstack.top() << std::endl;
	mstack.pop(); // remove last one
	std::cout << "Size of Stack : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(-5);
	mstack.push(737);
	mstack.push(0);
	
	std::cout << "\nSizes of stack SWAP : " << std::endl;
	std::stack<int> foo,bar;
	foo.push (10); foo.push(20); foo.push(30);
	bar.push (111); bar.push(222);

	foo.swap(bar);

	std::cout << "size of foo: " << foo.size() << '\n';
	std::cout << "size of bar: " << bar.size() << '\n';

	bar.swap(foo);

	std::cout << "\nSizes of stack second SWAP : " << std::endl;
	std::cout << "size of foo: " << foo.size() << '\n';
	std::cout << "size of bar: " << bar.size() << '\n';


	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	std::cout << " \nNumbers still on the stack + added : " << std::endl;

	while (it != ite) {
		std::cout << *it << std::endl;
	++it;
	}

	std::stack<int> s(mstack); //s pour stack

	return (0);
}
