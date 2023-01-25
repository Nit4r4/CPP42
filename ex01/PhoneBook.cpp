/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:40:54 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/25 17:37:32 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	std::cout << "\e[32m*** My Awsome PhoneBook start with success ***\e[39m" << std::endl; //constructor call
	this->_countContact = 0; //initialisation du pointeur compteur de contact de la classe PhoneBook en private
	std::cout << " " << std::setfill('-') << std::setw(51) << "\n";
	std::string titre = "My Awesome PhoneBook";
	for (int i=0; i<titre.length(); ++i)
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
	
	std::cout << str; //put a string
	std::getline(std::cin, info, '\n'); // std::getline(std::cin, infos, '\n'); '\n' pour la touche ENTREE ?
	if (std::cin.fail()) {
		std::cout << "An error has occured" << std::endl;
		exit (0);
	}
	if (!info.empty()) //a modifier si quelque chose ne fonctionne pas comme prevu
		return info;
	return (0);
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

void	PhoneBook::printSearchContact(int i) { //put contacts into array contacts[]
	std::cout << "First name : " << this->contacts[i].getFirstName() << std::endl;
	std::cout << "Last name : " << this->contacts[i].getLastName() << std::endl;
	std::cout << "Nickname : " << this->contacts[i].getNickname() << std::endl;
	std::cout << "Phone number : " << this->contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret, shhh! : " << this->contacts[i].getDarkestSecret() << std::endl;
}

void	buildIndexFormat(std::string info) {
	//std::cout << std::setfill('-') << std::setw(10) << "\n" << std::endl;
	//std::cout << "|";
	if (info.length() > 10) {
		info.resize(9);
		info.append(1u, '.');
	}
	else 
		std::cout << std::setfill(' ') << std::setw(10) << std::right << info << "|";
	//	std::cout << std::setfill(' ') << std::setw(10) << std::right << info << "|";
		//std::cout << std::right << info << "|";
}

void	PhoneBook::buildIndexInfos(int i) {
	int	j;
	if (i < 1 || i > 8) {
		std::cout << "\033[34mPlease select a number between 1 and 8\e[39m" << std::endl;
		//i &= ~(1 << 0);
		j = i;
		std::cin >> j;
		buildIndexInfos(j);
	}
	if (i > 0 && i < 9) {
		//i &= ~(1 << 0);
		if (this->contacts[i - 1].getFirstName().empty()) {
			std::cout << NO_CONTACT << std::endl;
			i = false;
			return ;
		}
		std::cout << "┌" << std::setfill('-') << std::setw(46) << std::right << "┐" << std::endl;
		std::cout << std::left << "|" << I << FN << LN << NN << std::endl;
		std::cout << "├" << std::setfill('-') <<std::setw(46) << std::right << "┤" << std::endl;
		std::cout << "|";
		std::cout << std::right << std::setfill(' ') << std::setw(10) << i << "│"; //ici endl enleve
		buildIndexFormat(this->contacts[i - 1].getFirstName());
		buildIndexFormat(this->contacts[i - 1].getLastName());
		buildIndexFormat(this->contacts[i - 1].getNickname());
		std::cout << "\n";
		std::cout << "└" << std::setfill('-') << std::setw(46) <<std::right << "┘" << "\n" << std::endl;
	}
}

// void	PhoneBook::buildIndexInfos(int i) {
// 	bool isValid = false;
// 	while (!isValid) {
// 		std::cout << "\033[34mPlease select a number between 1 and 8\e[39m" << std::endl;
// 		std::cin >> i;
// 		if (i < 1 || i > 8) {
// 			std::cout << "\033[34mPlease select a number between 1 and 8\e[39m" << std::endl;
// 	}
// 	else 
// 		isValid = true;
// 	}
// 	if (i > 0 && i < 9) {
// 		if (this->contacts[i - 1].getFirstName().empty()) {
// 			std::cout << NO_CONTACT << std::endl;
// 			return;
// 		}
// 		std::cout << std::setfill('-') << std::setw(10);
// 		std::cout << std::left << "|" << I << FN << LN << NN << std::endl;
// 		std::cout << std::setfill(' ') << std::setw(10) << i << "│" << std::endl;
// 		std::cout << std::setfill('-') << std::setw(10);
// 		buildIndexFormat(this->contacts[i - 1].getFirstName());
// 		buildIndexFormat(this->contacts[i - 1].getLastName());
// 		buildIndexFormat(this->contacts[i - 1].getNickname());
// 		std::cout << std::endl;
// 	}
// }
