/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:40:54 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/31 11:28:24 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "\e[32m*** My Awsome PhoneBook start with success ***\e[39m" << std::endl; //constructor call
	this->_countContact = 0; //initialisation du pointeur compteur de contact de la classe PhoneBook en private
	std::cout << " " << std::setfill('-') << std::setw(51) << "\n";
	std::string titre = "My Awesome PhoneBook";
	for (int i=0; i < (int)titre.length(); ++i)
	{
	titre[i] = ::toupper(titre[i]);
	}
	std::cout << "|" << std::setfill(' ') << std::setw(50) << std::left << titre << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(51) << std::right << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(50) << std::left << "User information :" << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(50) << std::left << "to add a contact please type ADD" << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(50) << std::left << "to search a contact please type SEARCH" << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(50) << std::left << "to exit this Awesome PhoneBook please type EXIT" << "|";
	std::cout << "  " << std::setfill('-') << std::setw(51) << "\n" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "\e[32m*** My Awesome PhoneBook ended with success ***\e[39m" << std::endl; //destructor call
}

int	PhoneBook::getCountedContact() const {
	return this->_countContact;
}

std::string	getStreamInfos(std::string str) {
	std::string	info;
	
	std::cout << str;
	info.clear();
	while (true) {
		std::getline(std::cin, info, '\n');
		if (!info.empty()) {
			if (std::cin.fail()) {
				std::cout << "An error has occured" << std::endl;
				exit (0);
			}
			std::cout << "You entered : " ;
			std:: cout << info << std::endl;
			return info;
		}
		std::cout << ":'( Please feed me : ";
	}
	return (0);
}

void	PhoneBook::addContact(void) { //buildDataBasePhoneBook
	std::string	info;

	info = getStreamInfos("Please enter you first name : "); //sg fault si rien
	this->contacts[_countContact].setFirstName(info);
	info = getStreamInfos("Please enter your last name : ");
	this->contacts[_countContact].setLastName(info);
	info = getStreamInfos("Please enter your nickname : ");
	this->contacts[_countContact].setNickname(info);
	info = getStreamInfos("Please enter your phone number : ");
	this->contacts[_countContact].setPhoneNumber(info);
	info = getStreamInfos("Please tell us your darkest secret : ");
	this->contacts[_countContact].setDarkestSecret(info);
	this->_countContact = (this->_countContact + 1) % 8;
}

void	PhoneBook::printSearchContact(int i) { //put contacts into array contacts[]
	std::cout << "First name : " << this->contacts[i].getFirstName() << std::endl;
	std::cout << "Last name : " << this->contacts[i].getLastName() << std::endl;
	std::cout << "Nickname : " << this->contacts[i].getNickname() << std::endl;
	std::cout << "Phone number : " << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret, shhh! : " << this->contacts[i].getDarkestSecret() << std::endl;
}

void	buildIndexFormat(std::string info) {
	if (info.length() > 10) {
		std::cout << info.substr(0, 9).append(".");
		std::cout << std::right << "|";
		//info.resize(9);
		//info.append(1, '.');
	}
	else 
		std::cout << std::setfill(' ') << std::setw(10) << std::right << info << "|";
}

void	PhoneBook::buildIndexInfos(int i) {
	int	j;
	if (i < 1 || i > 8) {
		std::cout << "\033[34mPlease select a number between 1 and 8\e[39m" << std::endl;
		j = i;
		std::cin >> j;
		buildIndexInfos(j);
	}
	if (i > 0 && i < 9) {
		if (this->contacts[i - 1].getFirstName().empty()) {
			std::cout << NO_CONTACT << std::endl;
			i = false;
			return ;
		}
		std::cout << "┌" << std::setfill('-') << std::setw(46) << std::right << "┐" << std::endl;
		std::cout << std::left << "|" << I << FN << LN << NN << std::endl;
		std::cout << "├" << std::setfill('-') <<std::setw(46) << std::right << "┤" << std::endl;
		std::cout << "|";
		std::cout << std::right << std::setfill(' ') << std::setw(10) << i << "│";
		buildIndexFormat(this->contacts[i - 1].getFirstName());
		buildIndexFormat(this->contacts[i - 1].getLastName());
		buildIndexFormat(this->contacts[i - 1].getNickname());
		std::cout << "\n";
		std::cout << "└" << std::setfill('-') << std::setw(46) <<std::right << "┘" << "\n" << std::endl;
	}
}
