/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:30:57 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/23 15:04:27 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("DefaultTarget") {
	//std::cout << " Constructor RRF called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	//std::cout << " Destructor RRF called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	//std::cout << " Constructor string RRF called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {
	(*this) = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &assign) {
	if (this != &assign)
	{
		AForm::operator=(assign);
		_target = assign._target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (getSign())
	{
		if (executor.getGrade() <= getExecGrade())
		{
			std::cout << "Sbiiiiiiir ?" << std::endl;
			if (std::rand() % 2)
			{
				std::cout << _target
						  << " robotomy process works, unfortunatly The Robot is back."<< std::endl;
			}
			else
			{
				std::cout << "Robotomy process failed, please try again" << std::endl;
			}
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
