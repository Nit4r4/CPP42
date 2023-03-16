/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:14:12 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/13 09:38:38 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "📂 AAnimal super class constructor called" << std::endl;
	type = "AAnimal";
}

AAnimal::~AAnimal(){
		std::cout << "📁 AAnimal super class destructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &copy) : type(copy.type) {
		std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &assign) {
	std::cout << "AAnimal assignment constructor called" << std::endl;
	this->type = assign.getType();
	return *this;
}

std::string	AAnimal::getType(void) const {
	return type;
}

void	AAnimal::makeSound(void) {
	std::cout << "🛑 AAnimals makes different sounds, but I am not an AAnimal, I am just a Class" << std::endl;
}