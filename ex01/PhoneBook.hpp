/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:26:53 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/25 11:41:22 by vferraro         ###   ########.fr       */
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
# define NO_CONTACT "This entry does not have a registered contact, you can add one by taping ADD"
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
	void	buildIndexInfos(int i);

private:

	Contact	contacts[8];                   //tableau de int du nombre de contact max 8
	int	_countContact;                    // _ car private
	
};

#endif