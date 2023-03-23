/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:50:33 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/23 14:05:53 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Intern;
#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <exception>
# include <stdexcept>

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public :
		Intern();
		Intern(std::string name, int grade);
		~Intern();
		Intern(Intern const &copy);
		Intern &operator=(Intern const &assign);

		AForm*	makeForm(std::string formName, std::string formTarget);

};

std::ostream	&operator<<(std::ostream &out, const Intern &obj);

#endif