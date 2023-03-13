/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:23:25 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/13 16:02:26 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Bureau is open, bureaucrat takes his coffee" << std::endl;
}

Bureaucrat(std::string name, int _grade) _name(name) {
	
}

Bureaucrat::Bureaucrat() {
	std::cout << "Bureau is open, bureaucrat takes his coffee" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureau is close, bureaucrat turns back home" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) {
	
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &assign);

std::string	Bureaucrat::getName() const;
int			Bureaucrat::getGrade() const;

void	Bureaucrat::increaseGrade();
void	Bureaucrat::decreaseGrade();

const char	Bureaucrat::GradeTooHighException {
	return ("Above the sky there is the sun but think about Icare...");
}

const char	Bureaucrat::GradeTooLowException {
	return ("Into deep (it's a great song !)");
}