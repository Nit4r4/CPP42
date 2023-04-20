#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <limits>

class Span {
public:
	Span(unsigned int N);
	~Span();
	Span(const Span& copy);
	Span& operator=(const Span& assign);

	void addNumber(int n);
	template <typename InputIterator>
	void addNumber(InputIterator begin, InputIterator end);

	int shortestSpan();
	int longestSpan();

	class SpanException : public std::exception {
	public:
		SpanException(const char* msg) : _msg(msg) {}
		const char* what() const throw() { 
			return _msg;
			}

	private:
		const char* _msg;
	};

private:
	unsigned int _N;
	std::vector<int> _nums;
};

#endif
