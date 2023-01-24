/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:40:54 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/24 15:41:23 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "PhoneBook Constructor called" << std::endl;
	this->_countContact = 0; //initialisation du pointeur compteur de contact de la classe PhoneBook en private
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook Destructor called" << std::endl;
}

int	PhoneBook::getCountedContact() const {
	return this->_countContact;
}

std::string	getStreamInfos(std::string str) {
	std::string	info;
	
	std::cout << str; //put a string
	std::getline(std::cin, info, '\n'); // std::getline(std::cin, infos, '\n'); '\n' pour la touche ENTREE ?
	if (std::cin.fail()) {
		std::cout << "An error has occured" << std::endl;
		return;
	}
	if (!info.empty()) //a modifier si quelque chose ne fonctionne pas comme prevu
		return info;
	return;
}

void	PhoneBook::addContact(void) { //buildDataBasePhoneBook
	std::string	info;

	info = getStreamInfos("Please enter you first name : ");
	this->contacts[_countContact].setFirstName(info);
	info = getStreamInfos("Please enter your last name : ");
	this->contacts[_countContact].setLastName(info);
	info = getStreamInfos("Please enter your nickname : ");
	this->contacts[_countContact].setNickname(info);
	info = getStreamInfos("Please enter your phone number : ");
	this->contacts[_countContact].setPhoneNumber(info);
	info = getStreamInfos("Please tell us your darkest secret : ");
	this->contacts[_countContact].setDarkestSecret(info);
	this->_countContact += 1;
	if (_countContact > 8) {
		this->contacts[0] = this->contacts[_countContact];
		std::swap(contacts[0], contacts[1]);
		std::swap(contacts[1], contacts[2]);
		std::swap(contacts[2], contacts[3]);
		std::swap(contacts[3], contacts[4]);
		std::swap(contacts[4], contacts[5]);
		std::swap(contacts[5], contacts[6]);
		std::swap(contacts[6], contacts[7]);
	}
}

void	PhoneBook::printSearchContact(int i) {
	if (this->contacts[i].getFirstName().empty())
		std::cout << NO_CONTACT << std::endl;
	std::cout << "First name : " << this->contacts[i].getFirstName() << std::endl;
	std::cout << "Last name : " << this->contacts[i].getLastName() << std::endl;
	std::cout << "Nickname : " << this->contacts[i].getNickname() << std::endl;
	std::cout << "Phone number : " << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret, shhh! : " << this->contacts[i].getDarkestSecret() << std::endl;
}


buildIndex

setExitWord
clear string .clear