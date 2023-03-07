/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:14:15 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/07 15:33:44 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
	public :
		Brain();
		virtual ~Brain();
		Brain(Brain const &copy);
		Brain	&operator=(Brain const &assign);

		std::string	getType(void) const;

		std::string ideas[100];

	protected :
		std::string	_brain;
};

#endif