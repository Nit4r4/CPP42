/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:01:36 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/13 09:37:00 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
	public :
		Dog();
		~Dog();
		Dog(Dog const &copy);
		Dog	&operator=(Dog const &assign);

		virtual void	makeSound();
		
		void		setIdea(std::string idea, int i) const;
		std::string	getIdea(int i) const;

	private :
		Brain*	_brain;
};

#endif