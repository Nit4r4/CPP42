/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:04:51 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/07 15:02:34 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "🏗 Constructor Wrong Animal called" << std::endl;
	type = "Wrong Animal";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "🚧 Destructor Wrong Animal called" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const &copy) : type(copy.type) {
	std::cout << "Constructor copy Wrong Animal called" << std::endl;
	//*this = copy;
}
WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &assign) {
	std::cout << "Wrong Animal assignment constructor called" << std::endl;
	this->type = assign.getType();
	return *this;
}

std::string	WrongAnimal::getType(void) const {
	return type;
}

// void	WrongAnimal::setType(const std::string newType) {
// 	this->type = newType;
// }

void	WrongAnimal::makeSound() const {
	std::cout << "❌ No sound, I am a Wrong Animal, wathever it means..." << std::endl;
}