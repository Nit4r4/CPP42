/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:14:12 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/06 14:14:59 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : Animal("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(){
		std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &copy) : type(copy.type) {
		std::cout << "Animal copy constructor called" << std::endl;
}

Animal	&operator=(Animal const &assign) {
	std::cout << "Animal assignment constructor called" << std::endl;
	this->type = assign.getType();
	return *this;
}

std::string	const getType(void) {
	return type;
}
	
void	setType(const newType) {
	this->type = newType;
}