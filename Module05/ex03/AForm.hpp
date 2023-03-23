/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:44:45 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/23 11:29:07 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class AForm;
#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <exception>
# include <stdexcept>

# include "Bureaucrat.hpp"

class AForm {
private :
	std::string	const _name;
	bool	_signed;
	int		const _signGrade;
	int		const _execGrade;

public :
	AForm();
	virtual ~AForm();
	AForm(std::string name, int signGrade, int execGrade);
	AForm(AForm const &copy);
	AForm &operator=(AForm const &assign);

	void		beSigned(Bureaucrat &obj);
	virtual void execute(Bureaucrat const &executor) const = 0;

	std::string	getName() const;
	bool		getSign() const;
	int			getSignGrade() const;
	int			getExecGrade() const;

	class GradeTooHighException : public std::exception {
			public :
				virtual const char *what() const throw();
		};

	class GradeTooLowException : public std::exception {
			public :
				virtual const char *what() const throw();
		};

	class SignException : public std::exception {
		public:
			virtual const char* what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, const AForm &obj);

#endif