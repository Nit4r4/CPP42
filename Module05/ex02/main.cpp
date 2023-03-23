/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:56:52 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/23 13:45:06 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int	main(void) {
	std::cout << " " << std::endl;
	std::cout << "***** FORM TESTS *****" << std::endl;
	std::cout << " " << std::endl;
	
	std::cout << "Construction of valid grade Bureaucrats : " << std::endl;
	try {
		Bureaucrat Philomena("Philo", 4);
		PresidentialPardonForm sorry = PresidentialPardonForm("CEO");
		//AForm *okForm = new PresidentialPardonForm(sorry);
		std::cout << Philomena;
		Philomena.signForm(sorry);
		Philomena.executeForm(sorry);
	}
	catch (AForm::GradeTooLowException &tooLow) {
		std::cout << tooLow.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;


	std::cout << "Construction of limite grade Bureaucrats : " << std::endl;
	try {
		Bureaucrat Roger("Roger", 150);
		PresidentialPardonForm PF = PresidentialPardonForm("The Pres Form MF");
		std::cout << Roger;
	//	PresidentialPardonForm *PresForm = new PresidentialPardonForm(PF);
		Roger.signForm(PF);
		std::cout << PF;
	}
	catch (AForm::GradeTooLowException &tooLow) {
		std::cout << tooLow.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;
	
	std::cout << "Construction of unvalid grade Bureaucrats : " << std::endl;
	try {
		Bureaucrat Sunny("Sunny", 0); // too high
		Bureaucrat Dante("Dante", 151); // to low
		PresidentialPardonForm notOkForm = PresidentialPardonForm("Not OK");
		//PresidentialPardonForm *NotOK = new PresidentialPardonForm(notOkForm);
		std::cout << Sunny;
		std::cout << Dante;
		std::cout << " \n";
		Sunny.signForm(notOkForm);
		Dante.signForm(notOkForm);
		std::cout << notOkForm;
	}
	catch (AForm::GradeTooLowException &tooLow) {
		std::cout << tooLow.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;

	std::cout << "Increase or decrease grades of Bureaucrats : \n" << std::endl;
	try {
		PresidentialPardonForm PresForm = PresidentialPardonForm("Ditcature");
		//PresidentialPardonForm *Dicta = new PresidentialPardonForm(PresForm);
		Bureaucrat Sunny("Sunny", 0); // too high
		std::cout << "Goodbye " << Sunny.getName() << " you were " << Sunny.getGrade() << " grade ! It's too high...\n" << std::endl;
		std::cout << "Trying to call back " << Sunny.getName() << " but he's " << Sunny.getGrade() << " ";
		std::cout << Sunny;
		Bureaucrat Philomena("Philo", 34);
		Bureaucrat David("DD", 1);
		Sunny.decreaseGrade();
		Philomena.increaseGrade();
		Philomena.decreaseGrade();
		std::cout << David.getName() << " ";
		David.increaseGrade();
		David.signForm(PresForm);
		Sunny.signForm(PresForm);
		Philomena.signForm(PresForm);
	}
	catch (AForm::GradeTooLowException &tooLow) {
		std::cout << tooLow.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;

	std::cout << " " << std::endl;
	std::cout << "***** ROBOTOMY TESTS *****" << std::endl;
	std::cout << " " << std::endl;

	std::cout << "Unvalid Exec Bureaucrat RobotomyRequestForm : \n" << std::endl; 
	{
		Bureaucrat low = Bureaucrat("Low", 150);
		Bureaucrat ok = Bureaucrat("Mitch", 70);
		Bureaucrat Sergio = Bureaucrat("Sergio", 20);
		AForm *formR = new RobotomyRequestForm("ClapTrap");
		{
			try
			{
				low.executeForm(*formR);
			}
			catch (RobotomyRequestForm::SignException &se)
			{
				std::cout << se.what() << std::endl;
			}
		}
		{
			try
			{
				low.signForm(*formR);
				low.executeForm(*formR);
			}
			catch (RobotomyRequestForm::GradeTooLowException &gtle)
			{
				std::cout << gtle.what() << std::endl;
			}
		}
		//std::cout << ok;
		std::cout << low;
		std::cout << *formR;
		delete formR;
	}
	std::cout << "--------------------------------------------" << std::endl;

	std::cout << "Valid Sign Bureaucrat RobotomyRequestForm : \n" << std::endl; 
	{
		Bureaucrat low = Bureaucrat("Low", 150);
		Bureaucrat ok = Bureaucrat("Mitch", 70);
		Bureaucrat Sergio = Bureaucrat("Sergio", 20);
		AForm *formR = new RobotomyRequestForm("ClapTrap");
		{
			try
			{
				Sergio.executeForm(*formR); // pas encore sign
			}
			catch (RobotomyRequestForm::SignException &se)
			{
				std::cout << se.what() << std::endl;
			}
		}
		{
			try
			{
				Sergio.signForm(*formR);
				Sergio.executeForm(*formR); // sign ok
			}
			catch (RobotomyRequestForm::GradeTooLowException &gtle)
			{
				std::cout << gtle.what() << std::endl;
			}
		}
		std::cout << Sergio;
		std::cout << *formR;
		delete formR;
	}
	std::cout << "--------------------------------------------" << std::endl;

std::cout << "Valid Exec Bureaucrat RobotomyRequestForm : \n" << std::endl; 
	{
		Bureaucrat low = Bureaucrat("Low", 150);
		Bureaucrat ok = Bureaucrat("Mitch", 4);
		Bureaucrat Sergio = Bureaucrat("Sergio", 20);
		AForm *formR = new RobotomyRequestForm("ClapTrap");
		{
			try
			{
				ok.executeForm(*formR); // pas encore sign
			}
			catch (RobotomyRequestForm::SignException &se)
			{
				std::cout << se.what() << std::endl;
			}
		}
		{
			try
			{
				ok.signForm(*formR);
				ok.executeForm(*formR); // sign ok
			}
			catch (RobotomyRequestForm::GradeTooLowException &gtle)
			{
				std::cout << gtle.what() << std::endl;
			}
		}
		std::cout << ok;
		std::cout << *formR;
		delete formR;
	}
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "***** TREES TESTS *****" << std::endl;
	std::cout << " " << std::endl;
	std::cout << "Shrubbery : \n" << std::endl; 
	{
		Bureaucrat low = Bureaucrat("Low", 150);
		Bureaucrat ok = Bureaucrat("Mitch", 5);
		Bureaucrat Sergio = Bureaucrat("Sergio", 20);
		AForm *Garden = new ShrubberyCreationForm("Garden");
		low.signForm(*Garden);
		ok.signForm(*Garden);
		Sergio.signForm(*Garden);
				Garden->execute(ok);
		Garden->execute(Sergio);
		{
			try
			{
				Sergio.executeForm(*Garden); // pas encore sign
			}
			catch (ShrubberyCreationForm::SignException &se)
			{
				std::cout << se.what() << std::endl;
			}
		}
		{
			try
			{
				Sergio.signForm(*Garden);
				Sergio.executeForm(*Garden); // sign ok
			}
			catch (ShrubberyCreationForm::GradeTooLowException &gtle)
			{
				std::cout << gtle.what() << std::endl;
			}
		}
		std::cout << Sergio;
		std::cout << low;
		std::cout << ok;
		std::cout << *Garden;
		delete Garden;
	}
	std::cout << "--------------------------------------------" << std::endl;
}