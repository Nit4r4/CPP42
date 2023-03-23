/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:00:05 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/23 13:46:12 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", 145, 137), _target("DefaultTarget") {
//	std::cout << "Constructor SCF called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
//	std::cout << "Destructor SCF called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyForm", 145, 137), _target(target) {
//	std::cout << "Destructor string SCF called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {
	(*this) = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign){
	if (this != &assign)
	{
		AForm::operator=(assign);
		_target = assign._target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	std::string trees = "                       *%%%%%%%%%%%%%%%%%                                        \n";
				trees += "					%%%%%%%%%%%%%%%%%%%%%%%%%%                                    \n";
				trees += "					%%%%%%%%%%%%%%%%%%%%%%%%%%%/%                                 \n";
				trees += "		.%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%                               \n";
				trees += "	%%%%&&&&&&%&&&&&%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%      &&&&&&&&               \n";
				trees += " %%&%&&&&&&&%&&&&&&%%%%%%%%%%%&%%%%%%%%%%%%%%%%%%%&&%%%%%&&&&&&&&&%%%           \n";
				trees += " %%%&&&&&&&&&%%&&&&&&%%%%%%%&&&&&%&%%%&&&%%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%%      \n";
				trees += " %&&&&%&&&&&&&&&&&&&&&&&%%%&&&&&&&&&&&%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& \n";
 				trees += " %&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& \n";
 				trees += " %%%&%%&%&&&&&&&&&&&&&&&&%& &&&  &&&&&&& &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& \n";
				trees += "	   &&&.%&&&%&&&&&&&&& %&        #%        % &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&  \n";
				trees += "			   %&         %&         &          &&&&&@&&&&&&&&&&&&&&&&&&&&&&&&    \n";
				trees += "			   %&         %&         &          &&       &&&&   &&&&&&&&&&&       \n";
				trees += "				&         %&         &          %&       &         &              \n";
				trees += "				&         %&         &          &&       &         &              \n";
				trees += "				&         %&        %&          &&       &         &              \n";
				trees += "				&         %&        %&          &&       &         &&             \n";
				trees += "				&         %&        &&          &&       &         %&             \n";
				trees += "			   %&#        &&       *&&          &&      .&         %&             \n";
				trees += "			   &&&       #&&       &&&          &&       &          &,            \n";
				trees += "			  %&&&       %&&&      &&&         &&&      ,&          &&            \n";
				trees += "			  &&&      ..,,       %&&&      ,&&&&&&(*   %&&       /%&&&/,         \n";
				trees += "			#&&&&&#*,           .&(&&&&&&.              %&&                       \n";
				trees += "													   %&&&&/*                    \n";
	if (getSign())
	{
		if (executor.getGrade() <= getExecGrade())
		{
			std::cout << executor.getName() << " executed " << getName() << std::endl;
			std::ofstream out((_target + "_shrubbery").c_str());
			out << trees << std::endl;
			out.close();
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