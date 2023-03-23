/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:25 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/23 11:55:58 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Bureaucrat;
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <exception>
# include <stdexcept>

# include "AForm.hpp"

# define LOW "\e[31mToo low. Into deep (it's a great song !) \e[0m"
# define HIGH "\033[34mYou get to high. Above the sky there is the sun but think about Icare... \e[0m"

class Bureaucrat {
	public :
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &assign);

		std::string	getName() const;
		int			getGrade() const;

		void	increaseGrade();
		void	decreaseGrade();

		void	signForm(AForm &obj);
		void	executeForm(AForm const &form);

		class GradeTooHighException : public std::exception {
			public :
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char *what() const throw();
		};

	private :
		std::string	const _name;
		int			_grade;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &obj);

#endif