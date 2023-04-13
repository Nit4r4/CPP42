#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <stdexcept>

#define errMess "Occurence not found : "

class MyException : public std::exception {
public:
	virtual const char* what() const throw() {
		return errMess;
	}
};

template<typename T>
int easyfind(T& type, int n){
  // using std::find with vector and iterator:
  typename T::iterator it;

  it = std::find(type.begin(), type.end(), n);
	if (it != type.end()) {
		std::cout << "Element found : " << n << '\n';
		return 0;
		//std::cout << *it << std::endl;
	}
	throw MyException();
}



/* lst1.end() ne correspond pas au ernier element de la liste, mais que le dernier element a ete depasse*/



#endif