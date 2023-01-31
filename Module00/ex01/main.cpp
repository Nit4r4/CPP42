/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:30:35 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/31 15:37:22 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	std::string	str;
	int	ok = false;
	PhoneBook	PhoneBook;
	
	if (argc > 1) {
		std::cout << "This program does not accept any aguments, please try again" << std::endl;
		return (1);
	}
	while (true) {
		std::cout << "Type your command here: " << std::endl;
		std::getline(std::cin, str, '\n');
		if (std::isdigit(str[0]) == true)
				std::cout << COMMANDS << std::endl;
		if (str.compare(ADD) > 0 && str.compare(SEARCH) > 0 && str.compare(EXIT) > 0)
			std::cout << "\e[31mPlease just type ADD, SEARCH or EXIT int uppercase to use My Awesome PhoneBook\e[39m" << std::endl;
		else if (str.compare(ADD) == 0) {
				PhoneBook.addContact();
				ok = true;
		}
		else if (str.compare(SEARCH) == 0) {
			if (ok == true) {
				PhoneBook.buildIndexInfos();
				std::cout << "You can show all the information of a contact with his index position (1 to 8): ";
				std::getline(std::cin, str, '\n');
				PhoneBook.printSearchContact(atoi(str.c_str()));
			}
			else 
				std::cout << NO_CONTACT << std::endl;
		}
		else if (str.compare(EXIT) == 0)
			return (0);
	}
	return (0);
}