/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 09:41:15 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/23 12:09:36 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("The Presidential Pardon Form", 25, 5), _target("DefaultTarget") {
	//std::cout << " Constructor PDF called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	//std::cout << " Destructor PDF called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("The Presidential Pardon Form", 25, 5), _target(target) {
	//std::cout << " Constructor string PDF called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy) {
	(*this) = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &assign) {
	if (this != &assign)
	{
		AForm::operator=(assign);
		_target = assign._target;
	}
	return (*this);
}


void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (getSign())
	{
		if (executor.getGrade() <= getExecGrade())
		{
			std::cout << _target
					  << " has been forgiven by Zaphod Beeblebrox." << std::endl;
		}
		else
		{
			throw AForm::GradeTooLowException();
		}
	}
	else
	{
		throw AForm::SignException();
	}
}
