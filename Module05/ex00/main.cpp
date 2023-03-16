/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:56:52 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/16 12:24:31 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << " " << std::endl;
	std::cout << "***** BASICS TESTS *****" << std::endl;
	std::cout << " " << std::endl;
	
	std::cout << "Construction of valid grade Bureaucrats : " << std::endl;
	try {
		Bureaucrat Philomena("Philo", 34);
		Bureaucrat Paula("Popo", 82);
		std::cout << Philomena;
		std::cout << Paula;
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
		Bureaucrat David("DD", 1);
		std::cout << Roger;
		std::cout << David;
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
		std::cout << Sunny;
		std::cout << Dante;
	}
	catch (Bureaucrat::GradeTooLowException &tooLow) {
		std::cout << tooLow.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;

	// std::cout << "Welcome " << Philomena.getName() << " you are " << Philomena.getGrade() << " grade !" << std::endl;
	// std::cout << "Welcome " << Paula.getName() << " you are " << Paula.getGrade() << " grade !" << std::endl;
	// std::cout << "Welcome " << Roger.getName() << " you are " << Roger.getGrade() << " grade !" << std::endl;
	// std::cout << "Welcome " << David.getName() << " you are " << David.getGrade() << " grade !" << std::endl;
	
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
}