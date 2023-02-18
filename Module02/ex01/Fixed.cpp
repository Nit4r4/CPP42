/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:15:18 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/18 17:02:33 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

	Fixed::Fixed() : _valViFix(0) {
		std::cout << "Default constructor called" << std::endl;
	}

	Fixed::Fixed(Fixed const &copy) {
		std::cout << "Copy constructor called" << std::endl;
		*this = copy;
	}
	
	Fixed	&Fixed::operator = (Fixed const &assign) {
		std::cout << "Copy assignment operator called" << std::endl;
		this->_valViFix = assign._valViFix;
		return *this;
	}

	Fixed::~Fixed() {
		std::cout << "Destructor called" << std::endl;

	}

	std::ostream &operator<<(std::ostream &oos, const Fixed &assign) {
		oos << assign.toFloat();
		return oos;
}

	int	Fixed::getRawBits(void) const {
	//	std::cout << "getRawBits member function called" << std::endl;
		return _valViFix;
	}

	void	Fixed::setRawBits(int const raw) {
		this->_valViFix = raw;
	}

	float Fixed::toFloat() const {
	float pow = (1 << _bit);
	return _valViFix / pow;
}

	int Fixed::toInt() const {
		return _valViFix >> _bit;
}

Fixed::Fixed(int const intNbr) {
	_valViFix = intNbr << _bit;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const floatNbr) {
	_valViFix = roundf(floatNbr * (1 << _bit));
	std::cout << "Float constructor called" << std::endl;
}