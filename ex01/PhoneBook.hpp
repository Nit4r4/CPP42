/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:26:53 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/18 15:48:58 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Contact.hpp"

class PhoneBook
{
public:

	PhoneBook(void);     //constructor
	~PhoneBook(void);    //destructor

							//fonction

private:

	Contact	contacts[8];     //tableau de int
	int	_countContact;		// _ car private
	
};

#endif