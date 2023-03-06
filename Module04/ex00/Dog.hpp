/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:01:36 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/06 14:27:20 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
	public :
		Dog();
		virtual ~Dog();
		Dog(Dog const &copy);
		Dog	&operator=(Dog const &assign);

		void	makeSound() const;
};

#endif