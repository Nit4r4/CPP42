/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:13:10 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/06 15:06:43 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat wakes up 🐈" << std::endl;
	type = "Cat";
}

// Cat::Cat() : type("Cat") {
// 	std::cout << "Cat wake up" << std::endl;
// }

Cat::~Cat(){
		std::cout << "Cat return to sleep" << std::endl;
}

Cat::Cat(Cat const &copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->type = copy.getType();
}

Cat	& Cat::operator=(Cat const &assign) {
	std::cout << "Cat assignement constructor called" << std::endl;
	this->type = assign.getType();
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "😽 Miaaaaaw" << std::endl;
}