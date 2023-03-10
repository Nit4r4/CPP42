/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:01:50 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/07 14:46:27 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	public :
		Animal();
		virtual ~Animal();
		Animal(Animal const &copy);
		Animal	&operator=(Animal const &assign);

		std::string	getType(void) const; //attention mettre le const a la fin !
		//void		setType(const std::string newType); // pas besoin

		virtual void	makeSound(void) const;

	protected :
		std::string	type;
};

#endif