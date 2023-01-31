/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:26:53 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/31 15:29:09 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cctype>
# include "Contact.hpp"

# define ADD "ADD"
# define SEARCH "SEARCH"
# define EXIT "EXIT"
# define COMMANDS "\e[31mPlease just type ADD, SEARCH or EXIT int uppercase to use My Awesome PhoneBook\e[39m"
# define NO_CONTACT "\033[34mThis entry does not have a registered contact, you can add one by taping ADD\e[39m"
# define I "  INDEX   |"
# define FN " 1ST NAME |"
# define LN " LAST NAME|"
# define NN " NICKNAME |"

class PhoneBook
{
public:

	PhoneBook(void);                         //constructor
	~PhoneBook(void);                       //destructor

	int		getCountedContact(void) const;     //fonction
	void	addContact(void);
	void	printSearchContact(int i);
	void	buildIndexInfos(void);

private:

	Contact	contacts[8];                   //tableau de int du nombre de contact max 8
	int	_countContact;                    // _ car private
	int	_counter;
	
};

#endif