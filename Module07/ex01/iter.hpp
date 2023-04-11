/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:48:17 by vferraro          #+#    #+#             */
/*   Updated: 2023/04/11 13:20:03 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template<typename T>
void	ft_call(T const &array) {
	std::cout << array << std::endl;
}

template<typename T>
void iter(T *array, int sizeArray, void (*ft_call)(T const &array)) {
	for (int i = 0; i < sizeArray; i++)
		ft_call(array[i]);
}

#endif
