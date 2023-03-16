/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:44:45 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/16 12:53:06 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Form
{
private:
	std::string	const _name;
	bool	const _notSign;
	int		const _SignGrade;
	int		const _execGrade

public:
	Form(/* args */);
	~Form();
};



#endif