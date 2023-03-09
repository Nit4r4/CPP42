/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:01:50 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/09 14:45:05 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

# include "Brain.hpp"

class Animal {
	public :
		Animal();
		virtual ~Animal();
		Animal(Animal const &copy);
		Animal	&operator=(Animal const &assign);

		std::string	getType(void) const;

		virtual void	makeSound(void) const;

	protected :
		std::string	type;
};

#endif