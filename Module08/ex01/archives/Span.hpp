#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

#endif

class Span {
	private:
		unsigned int		_N;
		int					_maxN;
		std::vector<int>	_vector;

	public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(Span const &cpy);
		Span &operator=(const Span &assign);

		void	addNumber(int nbr);
		int		shortestSpan(void);
		int		longestSpan(void);

		class fullNumber : public std::exception {
			const char *what() const throw();
		}
};
