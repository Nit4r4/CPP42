/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:13:36 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/06 14:24:07 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog() : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
}

~Dog(){
		std::cout << "Dog destructor called" << std::endl;
}

Dog(Dog const &copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = copy.getType();
}

Dog	&operator=(Dog const &assign) {
	std::cout << "Dog assignment constructor called" << std::endl;
	this->type = assign.getType();
	return *this;
}

void	const makeSound() {
	std::cout << "Ouaf ouaf" << std::endl;
}