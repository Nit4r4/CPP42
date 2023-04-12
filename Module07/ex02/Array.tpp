/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:16:30 by vferraro          #+#    #+#             */
/*   Updated: 2023/04/12 16:51:12 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template<typename T>

class Array {
	private:
		T	*_tab;
		unsigned int	_n;

	public:
		Array() : _n(0) {
			_tab = new T[_n]; // empty array initialization
		}

		Array(unsigned int n) : _n(n) {
			_tab = new T[_n];
		}

		Array(const Array &copy) : _n(copy._n) {
			_tab = NULL;
			*this = copy;
		}

		~Array() {
			delete [] _tab;
		}

		Array &operator=(const Array &assign) {
			if (this != &assign) {
				delete [] _tab;
				_n = assign.size();
				_tab = new T[_n];
				for (unsigned int i = 0; i < assign.size(); i++) {
				this->_tab[i] = assign._tab[i];
				}
			}
			return *this;
		}

		T &operator[](unsigned int i) {
			if ( i >= _n )
				throw MyException(); 
			return (this->_tab[i]);
		}

		class MyException : public std::exception {
			virtual const char *what() const throw();
		};

		unsigned int	size() const {
			return (_n);
		}
};

#endif