#include "Span.hpp"

Span::Span() : _N(0), _maxN(0), _vector(0) {}

Span::Span(unsigned int N) : _N(0), _maxN(_N), _vector(_N) {}

Span::~Span() {}

Span::Span(Span const &cpy) {
	*this = cpy;
}

Span &Span::operator=(Span const &assign) {
	if (this != &assign) {
		this->_N = assign._N;
		this->_maxN = assign._maxN;
		this->_vector = assign._vector;
	}
	return *this;
}

const char	*Span::fullNumber::what() const throw() {
	return "Not enough space left\n";
}

void	Span::addNumber(int nbr) {}

int	Span::shortestSpan(void) {

}

int	Span::longestSpan(void) {}