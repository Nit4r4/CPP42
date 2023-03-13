/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:51:25 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/13 16:00:12 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat {
	public :
		Bureaucrat();
		Bureaucrat(std::string _name, int _grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &assign);

		std::string	getName() const;
		int			getGrade() const;

		void	increaseGrade();
		void	decreaseGrade();

		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

	private :
		std::string	_name const;
		int			_grade;
};

Bureaucrat &operator=(Bureaucrat const &assign, _name, _grade) {
	
}