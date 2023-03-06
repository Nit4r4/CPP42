/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:13:36 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/06 15:06:51 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Dog() : type("Dog") {
// 	std::cout << "Dog wants to play" << std::endl;
// }

Dog::Dog() : Animal() {
	std::cout << "Dog wants to play 🐕" << std::endl;
	type = "Dog";
}

Dog::~Dog(){
		std::cout << "Dog turns back to its doghouse" << std::endl;
}

Dog::Dog(Dog const &copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = copy.getType();
}

Dog	& Dog::operator=(Dog const &assign) {
	std::cout << "Dog assignment constructor called" << std::endl;
	this->type = assign.getType();
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "🐶 Ouaf ouaf" << std::endl;
}

/* Ne pas oublier les Dog:: devant les Dog (fonctions) */