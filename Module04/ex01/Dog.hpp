/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:01:36 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/09 14:56:25 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal { // pas besoin de faire heriter de public Brain (?)
	public :
		Dog();
		~Dog();
		Dog(Dog const &copy);
		Dog	&operator=(Dog const &assign);

		void	makeSound() const;
		
		void		setIdea(std::string idea, int i) const;
		std::string	getIdea(int i) const;

	private :
		Brain*	_brain;
};

#endif