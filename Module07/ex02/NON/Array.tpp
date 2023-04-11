/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:16:30 by vferraro          #+#    #+#             */
/*   Updated: 2023/04/11 15:05:23 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _n(0) {
	_tab = new T[_n]; // empty array initialization
}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n) {
	_tab = new T[_n];
}

template <typename T>
Array<T>::Array(const Array &copy) : _n(copy._n) {
	_tab = NULL;
	*this = copy;
}

template <typename T>
Array<T>::~Array() {
	delete [] _tab;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &assign) {
	if (this != &assign) {
		delete [] _tab;
		_n = assign.size();
		_tab = new T[_n];
		for (unsigned int i; i < assign.size(); i++) {
		this->_tab[i] = assign._tab[i];
		}
	}
	return *this;
}

template <typename T>
T &Array<T> operator[](unsigned int i) {
	if (i >= _n)
		throw std::invalid_index("Index is invalid");
	return (this->_tab[i]);
}

template <typename T>
unsigned int	size() const {
	return (_n);
}
