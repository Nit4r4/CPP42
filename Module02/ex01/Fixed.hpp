/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:12:49 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/18 17:03:31 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> //roudf value to round

class Fixed {
	public:
		Fixed();									//constructor
		Fixed(Fixed const &copy);					// constructor copy
		Fixed(int const intNbr);
		Fixed(float const floatNbr);
		Fixed	&operator = (Fixed const &assign);	// Operator d'affectation
		~Fixed();									// destructor
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		float	toFloat(void) const;
		int		toInt(void) const;
		
	private:
		int	_valViFix;
		static int	const _bit = 8;
};

std::ostream &operator<<(std::ostream &oos, const Fixed &assign);

#endif