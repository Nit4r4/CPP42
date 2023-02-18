/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:12:49 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/18 17:30:59 by vferraro         ###   ########.fr       */
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
		~Fixed();									// destructor
		
		/* OPERATORS */

		Fixed	&operator = (Fixed const &assign);	// Operator d'affectation

		bool operator > (Fixed const &assign) const;
		bool operator >= (Fixed const &assign) const;
		bool operator < (Fixed const &assign) const;
		bool operator <= (Fixed const &assign) const;
		bool operator == (Fixed const &assign) const;
		bool operator != (Fixed const &assign) const;

		Fixed operator + (Fixed const &assign) const;
		Fixed operator - (Fixed const &assign) const;
		Fixed operator * (Fixed const &assign) const;
		Fixed operator / (Fixed const &assign) const;

		Fixed &operator ++ (void);
		Fixed operator ++ (int);
		Fixed &operator -- (void);
		Fixed operator -- (int);

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
		
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