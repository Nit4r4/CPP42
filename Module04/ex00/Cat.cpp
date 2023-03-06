/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:13:10 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/06 14:18:52 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(){
		std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = copy.getType();
}

Cat	&operator=(Cat const &assign) {
	std::cout << "Cat assignement constructor called" << std::endl;
	this->type = assign.getType();
	return *this;
}

void	const makeSound() {
	std::cout << "Miaaaaaw" << std::endl;
}