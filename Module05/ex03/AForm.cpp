/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:46:22 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/23 09:34:13 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Approved"), _signed(false), _signGrade(150), _execGrade(150) {
//	std::cout << "AForm constructor called" << std::endl;
}

AForm::~AForm() {
//	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
	//std::cout << "AForm constructor string called" << std::endl;
}

AForm::AForm(AForm const &copy) : _name(copy.getName()), _signed(copy.getSign()), _signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade()) {
	//std::cout << "AForm copy constructor string called" << std::endl;
	*this = copy;
}

AForm &AForm::operator=(AForm const &assign) {
	if (this != &assign)
		_signed = assign._signed;
	return *this;
}

void	AForm::beSigned(Bureaucrat &obj)
{
	try
	{
		if (obj.getGrade() > this->getSignGrade())
			throw AForm::GradeTooLowException();
		else
			this->_signed = true;
	}
	catch (std::exception &except)
	{
		std::cout << except.what() << std::endl;
	}
}

std::string	AForm::getName() const {
	return _name;
}

bool	AForm::getSign() const {
	return _signed;
}

int	AForm::getSignGrade() const {
	return _signGrade;
}

int	AForm::getExecGrade() const {
	return _execGrade;
}

std::ostream	&operator<<(std::ostream &out, const AForm &obj) {
	std::string	isItSigned;
	if (obj.getSign() == true)
		isItSigned = "Yes";
	else
		isItSigned = "No";
	out << "AForm " << obj.getName() << std::endl
		<< "Sign grade " << obj.getSignGrade() << std::endl
		<< "Exec grade " << obj.getExecGrade() << std::endl
		<< "Is the Aform signed ? " << isItSigned << std::endl;
	return out;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Sorry, your grade is to low !");
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Seriously ? Your grade is to high !");
}

const char* AForm::SignException::what() const throw() {
	return ("Form isn't signed");
}
