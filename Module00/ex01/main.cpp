/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:30:35 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/31 11:03:53 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	std::string	str;
	PhoneBook	PhoneBook;
	
	if (argc > 1) {
		std::cout << "This program does not accept any aguments, please try again" << std::endl;
		return (1);
	}
	while (true) {
		std::cout << "Type your command here: " << std::endl;
		std::getline(std::cin, str, '\n');
		if (str.compare(ADD) > 0 && str.compare(SEARCH) > 0 && str.compare(EXIT) > 0)
			std::cout << "\e[31mPlease just type ADD, SEARCH or EXIT int uppercase to use My Awesome PhoneBook\e[39m" << std::endl;
		else if (str.compare(ADD) == 0) //si c est egal
			PhoneBook.addContact();
		else if (str.compare(SEARCH) == 0) {
			std::cout << "You can find a contact with his index position (1 to 8): ";
			std::getline(std::cin, str, '\n');
			PhoneBook.buildIndexInfos(atoi(str.c_str()));
		}
		else if (str.compare(EXIT) == 0)
			return (0);
	}
	return (0);
}
