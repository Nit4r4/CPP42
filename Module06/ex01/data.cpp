#include "data.hpp"

/* Forme Canonique */
Data::Data() : _data(0) {}

Data::~Data() {}

Data::Data(const Data &cpy) {
	*this = cpy;
}

Data &Data::operator=(const Data &assign) {
	if (this != &assign)
		this->_data = assign._data;
	return *this;
}

/* Setter & Getter */

void	Data::setData(unsigned int data) {
	this->_data = data;
}

unsigned int	Data::getData(void) const {
	return this->_data;
}

/* Fonctions non membres */
uintptr_t	serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
