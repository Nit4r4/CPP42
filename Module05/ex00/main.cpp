/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:56:52 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/14 16:22:08 by vferraro         ###   ########.fr       */
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
	std::cout << "Increase or decrease grades of Bureaucrats : " << std::endl;
	try {
		Bureaucrat Sunny("Sunny", 0); // too high
		Bureaucrat Philomena("Philo", 34);
		Bureaucrat David("DD", 1);
		std::cout << Sunny;
		std::cout << Philomena;
		std::cout << David;
		Sunny.increaseGrade();
		Philomena.increaseGrade();
		Philomena.decreaseGrade();
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
	
}