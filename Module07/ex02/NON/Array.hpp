/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:16:30 by vferraro          #+#    #+#             */
/*   Updated: 2023/04/11 14:54:26 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>

class Array {
	private:
		T	*_tab;
		unsigned int	_n;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		~Array();

		Array &operator=(const Array &assign);
		T &operator[](unsigned int i);
};

#endif