/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:56:52 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/21 16:13:56 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	std::cout << " " << std::endl;
	std::cout << "***** BASICS TESTS *****" << std::endl;
	std::cout << " " << std::endl;
	
	std::cout << "Construction of valid grade Bureaucrats : " << std::endl;
	try {
		Bureaucrat Philomena("Philo", 34);
		//Bureaucrat Paula("Popo", 82);
		Form okForm("OK", 150, 150);
		std::cout << Philomena;
		//std::cout << Paula;
		Philomena.signForm(okForm);
		std::cout << okForm;
	}
	catch (Bureaucrat::GradeTooLowException &tooLow) {
		std::cout << tooLow.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;
	
	std::cout << "Construction of limite grade Bureaucrats : " << std::endl;
	try {
		Bureaucrat Roger("Roger", 150);
		//Bureaucrat David("DD", 1);
		std::cout << Roger;
		//std::cout << David;
		Form okForm("OK", 150, 150);
		Roger.signForm(okForm);
		std::cout << okForm;
	}
	catch (Bureaucrat::GradeTooLowException &tooLow) {
		std::cout << tooLow.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;
	
	std::cout << "Construction of unvalid grade Bureaucrats : " << std::endl;
	try {
		Bureaucrat Sunny("Sunny", 0); // too high
		Bureaucrat Dante("Dante", 151); // to low
		Form notOkForm("notOK", 150, 150);
		std::cout << Sunny;
		std::cout << Dante;
		Sunny.signForm(notOkForm);
		std::cout << " \n";
		Dante.signForm(notOkForm);
		std::cout << notOkForm;
	}
	catch (Bureaucrat::GradeTooLowException &tooLow) {
		std::cout << tooLow.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;

	std::cout << "Increase or decrease grades of Bureaucrats : \n" << std::endl;
	try {
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
	}
	catch (Bureaucrat::GradeTooLowException &tooLow) {
		std::cout << tooLow.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;

	std::cout << " " << std::endl;
	std::cout << "***** MORE TESTS *****" << std::endl;
	std::cout << " " << std::endl;

	std::cout << "Increase or decrease grades of Bureaucrats : \n" << std::endl;
	try {
		Bureaucrat Philomena("Philo", 34);
		Bureaucrat David("DD", 1);
		Bureaucrat TooHigh("Sky", -20);
		Bureaucrat TooLow("Abyss", 250);
		std::cout << Philomena;
		std::cout << David;
		std::cout << David.getName() << " ";
		David.increaseGrade();
		Philomena.decreaseGrade();
		std::cout << Philomena;
		std::cout << TooHigh.getName() << " ";
		std::cout << TooHigh;
		TooHigh.increaseGrade();
		std::cout << TooLow.getName() << " ";
		std::cout << TooLow;
		TooLow.decreaseGrade();
		std::cout << " \n";
		Form isForm("isForm", 150, 150);
		TooLow.signForm(isForm);
		std::cout << isForm;
		std::cout << "\n";
		TooHigh.signForm(isForm);
		std::cout << isForm;
		std::cout << " \n";
		Philomena.signForm(isForm);
		std::cout << isForm;
		std::cout << " \n";
		David.signForm(isForm);
		std::cout << isForm;
		std::cout << "\n" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &tooLow) {
		std::cout << tooLow.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;

	std::cout << "Increase or decrease grades of Bureaucrats FORM: \n" << std::endl;
	try {
		
		Bureaucrat Philomena("Philo", 34);
		Bureaucrat David("DD", 1);
		Bureaucrat TooHigh("Sky", -20);
		Bureaucrat TooLow("Abyss", 250);
		std::cout << Philomena;
		std::cout << David;
		std::cout << David.getName() << " ";
		David.increaseGrade();
		Philomena.decreaseGrade();
		std::cout << Philomena;
		std::cout << TooHigh.getName() << " ";
		std::cout << TooHigh;
		TooHigh.increaseGrade();
		std::cout << TooLow.getName() << " ";
		std::cout << TooLow;
		TooLow.decreaseGrade();
		std::cout << " \n";
		Form THEForm("THEForm", 152, 1250);
		TooLow.signForm(THEForm);
		std::cout << THEForm;
		std::cout << "\n";
		TooHigh.signForm(THEForm);
		std::cout << THEForm;
		std::cout << " \n";
		Philomena.signForm(THEForm);
		std::cout << THEForm;
		std::cout << " \n";
		David.signForm(THEForm);
		std::cout << THEForm;
		std::cout << "\n" << std::endl;
	}
	catch (Form::GradeTooLowException &tooLow) {
		std::cout << tooLow.what() << std::endl;
	}
	catch (Form::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;
}

/* pourquoi je n ai pas mes erreurs de Form qui sortent ???*/