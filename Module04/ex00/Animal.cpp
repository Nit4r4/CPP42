/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:14:12 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/06 15:18:45 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "📂 Animal constructor called" << std::endl;
	type = "Animal";
}

Animal::~Animal(){
		std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &copy) : type(copy.type) {
		std::cout << "Animal copy constructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &assign) {
	std::cout << "Animal assignment constructor called" << std::endl;
	this->type = assign.getType();
	return *this;
}

std::string	Animal::getType(void) const {
	return type;
}
	
void	Animal::setType(const std::string newType) {
	this->type = newType;
}

void	Animal::makeSound(void) const {
	std::cout << "🛑 Animals makes differents sound, but I am not an Animal, I am just a Class" << std::endl;
}