/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:40:45 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/24 14:36:27 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact() {
	std::cout << "Contact destructor called" << std::endl;
}

void	Contact::setFirstName(std::string str) {
	this->_FirstName = str;
}

void	Contact::setLastName(std::string str) {
	this->_LastName = str;
}

void	Contact::setNickname(std::string str) {
	this->_Nickname = str;
}

void	Contact::setPhoneNumber(std::string str) {
	this->_PhoneNumber = str;
}

void	Contact::setDarkestSecret(std::string str) {
	this->_DarkestSecret = str;
}

std::string	Contact::getFirstName(void) const {
	return this->_FirstName;
}

std::string	Contact::getLastName(void) const {
	return this->_LastName;
}

std::string	Contact::getNickname(void) const {
	return this->_Nickname;
}

std::string	Contact::getPhoneNumber(void) const {
	return this->_PhoneNumber;
}

std::string	Contact::getDarkestSecret(void) const {
	return this->_DarkestSecret;
}