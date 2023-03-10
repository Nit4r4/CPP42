/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:15:18 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/18 17:02:55 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

	Fixed::Fixed() : _valViFix(0) {
		std::cout << "Default constructor called" << std::endl;
		// ou comme ca : this->_valViFix = 0;
	}

	Fixed::Fixed(Fixed const &copy) {
		std::cout << "Copy constructor called" << std::endl;
		*this = copy;
	}
	
	Fixed	&Fixed::operator = (Fixed const &assign) {
		std::cout << "Copy assignment operator called" << std::endl;
		this->setRawBits(assign.getRawBits());
		return *this;
	}

	Fixed::~Fixed() {
		std::cout << "Destructor called" << std::endl;

	}

	int	Fixed::getRawBits(void) const {
		std::cout << "getRawBits member function called" << std::endl;
		return this->_valViFix;
	}

	void	Fixed::setRawBits(int const raw) {
		this->_valViFix = raw;
	}