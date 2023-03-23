/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:58:21 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/23 15:00:39 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern		&Intern::operator = (const Intern &assign)
{
	if (this == &assign)
		return (*this);
	return (*this);
}

AForm*		Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string		Forms[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	int				i = 0;

	while (i < 3 && Forms[i].compare(formName) != 0)
		i++;
	switch (i)
	{
		case 0 :
			std::cout << "Intern creates " << formName << std::endl;
			return (new ShrubberyCreationForm(formTarget));
		case 1 :
			std::cout << "Intern creates " << formName << std::endl;
			return (new RobotomyRequestForm(formTarget));
		case 2 :
			std::cout << "Intern creates " << formName << std::endl;
			return (new PresidentialPardonForm(formTarget));
		default :
			std::cout << "An error occured with the form. Please try again" << std::endl;
	}
	return NULL;
}
