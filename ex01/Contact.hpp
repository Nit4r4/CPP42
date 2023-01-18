/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:41:07 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/18 16:05:45 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
public:

	Contact(void);     //constructor
	~Contact(void);    //destructor

	/* FUNCTIONS */
	void	setFirstName(std::string str);						// setter ou mutateur
	void	setLastName(std::string str);						// setter ou mutateur
	void	setNickname(std::string str);						// setter ou mutateur
	void	setPhoneNumber(std::string str);					// setter ou mutateur
	void	setDarkestSecret(std::string str);					// setter ou mutateur

	std::string	getFirstName(void) const;						// getter ou accesseur
	std::string getNickname(void) const;						// getter ou accesseur
	std::string getLastName(void) const;						// getter ou accesseur
	std::string getPhoneNumber(void) const;						// getter ou accesseur
	std::string getDarkestSecret(void) const;					// getter ou accesseur

private:
	
	std::string _FirstName;
	std::string _LastName;
	std::string _Nickname;
	std::string _PhoneNumber;
	std::string _DarkestSecret;
	
};

#endif