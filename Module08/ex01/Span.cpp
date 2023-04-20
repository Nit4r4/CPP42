#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(const Span& copy) {
	*this = copy;
}

Span& Span::operator=(const Span& assign) {
	_N = assign._N;
	_nums = assign._nums;
	return *this;
}

void Span::addNumber(int n) {
	if (_nums.size() >= _N) {
		throw SpanException("Cannot add more numbers to Span.");
	}
	_nums.push_back(n);
}

template <typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end) {
	if (_nums.size() + std::distance(begin, end) > _N) {
		throw SpanException("Cannot add more numbers to Span.");
		return ;
	}
	_nums.insert(_nums.end(), begin, end);
}

int Span::shortestSpan() {
	if (_nums.size() < 2) {
		throw SpanException("Cannot find shortest span of Span.");
	}
	std::vector<int> sorted = _nums;
	std::sort(sorted.begin(), sorted.end());
	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 0; i < sorted.size() - 1; i++) {
		int span = sorted[i + 1] - sorted[i];
		if (span < shortest) {
			shortest = span;
		}
	}
	return shortest;
}

int Span::longestSpan() {
	if (_nums.size() < 2) {
		throw SpanException("Cannot find longest span of Span.");
	}
	int max = *std::max_element(_nums.begin(), _nums.end());
	int min = *std::min_element(_nums.begin(), _nums.end());
	return max - min;
}
