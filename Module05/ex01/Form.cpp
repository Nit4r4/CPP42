/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:46:22 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/23 08:53:17 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Approved"), _signed(false), _signGrade(150), _execGrade(150) {
	std::cout << "Form constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
	//std::cout << "Form constructor string called" << std::endl;
}

Form::Form(Form const &copy) : _name(copy.getName()), _signed(copy.getSign()), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade()) {
	std::cout << "Form copy constructor string called" << std::endl;
	*this = copy;
}

Form &Form::operator=(Form const &assign) {
	if (this != &assign)
		_signed = assign._signed;
	return *this;
}

void	Form::beSigned(Bureaucrat &obj)
{
	try
	{
		if (obj.getGrade() > this->getSignGrade())
			throw Form::GradeTooLowException();
		else
			this->_signed = true;
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}
}

std::string	Form::getName() const {
	return _name;
}

bool	Form::getSign() const {
	return _signed;
}

int	Form::getSignGrade() const {
	return _signGrade;
}

int	Form::getExecGrade() const {
	return _execGrade;
}

std::ostream	&operator<<(std::ostream &out, const Form &obj) {
	std::string	isItSigned;
	if (obj.getSign() == true)
		isItSigned = "Yes";
	else
		isItSigned = "No";
	out << "Form " << obj.getName() << std::endl
		<< "Sign grade " << obj.getSignGrade() << std::endl
		<< "Exec grade " << obj.getExecGrade() << std::endl
		<< "Is the form signed ? " << isItSigned << std::endl;
	return out;
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Sorry, your grade is to low !");
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Seriously ? Your grade is to high !");
}
