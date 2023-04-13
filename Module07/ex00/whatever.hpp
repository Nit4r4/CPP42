/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 08:39:43 by vferraro          #+#    #+#             */
/*   Updated: 2023/04/11 11:42:01 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <iomanip>

template<typename T>
void swap (T &a, T &b) {
	T c(a); a = b; b = c;
}

template<typename T>
const T &min (const T &a, const T &b) {
	return !(b <= a) ? a : b; // or: return (b > a) ? a : b if not equality;
}

template<typename T>
const T &max(const T &a, const T &b) {
	return ((a >= b) ? a : b); // or: return !(b > a) ? a : b;
}

#endif
