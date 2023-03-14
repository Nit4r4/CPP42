/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:23:25 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/14 15:27:43 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Bureau is open, bureaucrat takes his coffee" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	try
	{
		if (getGrade() < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (getGrade() > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureau is close, bureaucrat turns back home" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) {
	std::cout << "Bureaucrat makes a copy at the copy machine" << std::endl;
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &assign) {
	if (this != &assign) {
		//_name = assign._name;
		_grade = assign.getGrade();
	}
	std::cout << "Bureaucrat is assign to a task" << std::endl;
	return *this;
}

std::string	Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

void	Bureaucrat::increaseGrade() {
	try
	{
		if (getGrade() <= 1)
			throw Bureaucrat::GradeTooHighException();
		else
			_grade -= 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::decreaseGrade() {
	try
	{
		if (getGrade() >= 150)
			throw Bureaucrat::GradeTooLowException();
		else
			_grade += 1;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return (HIGH);
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return (LOW);
}

std::ostream	&operator <<(std::ostream &out, const Bureaucrat &obj)
{
	if (obj.getGrade() <= 100 && obj.getGrade() > 0) {
		out << "\e[32mWelcome " << obj.getName() << " you are " << obj.getGrade() << " grade !\e[0m" << std::endl;
	}
	else if (obj.getGrade() > 100  && obj.getGrade() <= 150) {
		out << "\033[35mWelcome " << obj.getName() << " you are " << obj.getGrade() << " grade...\e[0m" << std::endl;
	}
	return (out);
}
