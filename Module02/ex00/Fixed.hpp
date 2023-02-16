/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:12:49 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/16 14:36:11 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed();									//constructor
		Fixed(Fixed const &copy);					// constructor copy
		Fixed	&operator = (Fixed const &assign);	// Operator d'affectation
		~Fixed();									// destructor
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
	private:
		int	_valViFix;
		static int	const _bit = 8;
};

#endif