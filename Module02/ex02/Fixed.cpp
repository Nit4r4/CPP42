/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:15:18 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/18 17:24:40 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

	Fixed::Fixed() : _valViFix(0) {
		//std::cout << "Default constructor called" << std::endl;
	}

	Fixed::Fixed(Fixed const &copy) {
		//std::cout << "Copy constructor called" << std::endl;
		*this = copy;
	}
	
	Fixed::Fixed(int const intNbr) {
	_valViFix = intNbr << _bit;
	//std::cout << "Int constructor called" << std::endl;
}

	Fixed::Fixed(float const floatNbr) {
		_valViFix = roundf(floatNbr * (1 << _bit));
		//std::cout << "Float constructor called" << std::endl;
}

	Fixed::~Fixed() {
		//std::cout << "Destructor called" << std::endl;
	}
	
	Fixed	&Fixed::operator = (Fixed const &assign) {
		//std::cout << "Copy assignment operator called" << std::endl;
		this->_valViFix = assign._valViFix;
		return *this;
	}

	std::ostream &operator<<(std::ostream &oos, const Fixed &assign) {
		oos << assign.toFloat();
		return oos;
}

	bool Fixed::operator>(Fixed const &assign) const {
		return getRawBits() > assign.getRawBits();
	}

	bool Fixed::operator>=(Fixed const &assign) const {
		return getRawBits() >= assign.getRawBits();
	}

	bool Fixed::operator<(Fixed const &assign) const {
		return getRawBits() < assign.getRawBits();
	}

	bool Fixed::operator<=(Fixed const &assign) const {
		return getRawBits() <= assign.getRawBits();
	}

	bool Fixed::operator==(Fixed const &assign) const {
		return getRawBits() == assign.getRawBits();
	}

	bool Fixed::operator!=(Fixed const &assign) const {
		return getRawBits() != assign.getRawBits();
	}

	Fixed Fixed::operator+(Fixed const &assign) const {
		return Fixed(toFloat() + assign.toFloat());
	}

	Fixed Fixed::operator-(Fixed const &assign) const {
		return Fixed(toFloat() - assign.toFloat());
	}

	Fixed Fixed::operator*(Fixed const &assign) const{
		return Fixed(toFloat() * assign.toFloat());
	}

	Fixed Fixed::operator/(Fixed const &assign) const{
		return Fixed(toFloat() / assign.toFloat());
	}

	Fixed &Fixed::operator ++ (void) {
		this->_valViFix++;
		return *this;
	}

	Fixed Fixed::operator ++ (int) {
		Fixed tmp(*this);
		++(*this);
		return tmp;
	}

	Fixed &Fixed::operator -- (void) {
		this->_valViFix--;
		return *this;
	}

	Fixed Fixed::operator -- (int) {
		Fixed tmp(*this);
		--(*this);
		return tmp;
	}

	Fixed &Fixed::min(Fixed &a, Fixed &b) {
		return a <= b ? a : b;
	}

	const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
		return a <= b ? a : b;
	}

	Fixed &Fixed::max(Fixed &a, Fixed &b) {
		return a >= b ? a : b;
	}

	const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
		return a >= b ? a : b;
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
