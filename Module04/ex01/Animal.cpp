/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:14:12 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/07 14:36:51 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "📂 Animal super class constructor called" << std::endl;
	type = "Animal";
}

Animal::~Animal(){
		std::cout << "📁 Animal super class destructor called" << std::endl;
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

void	Animal::makeSound(void) const {
	std::cout << "🛑 Animals makes different sounds, but I am not an Animal, I am just a Class" << std::endl;
}