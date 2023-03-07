/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:04:54 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/07 14:11:37 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat wakes up ? 🐈" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat(){
		std::cout << "💤 WrongCat returns to sleep ?" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = copy.getType();
}

WrongCat	& WrongCat::operator=(WrongCat const &assign) {
	std::cout << "WrongCat assignement constructor called" << std::endl;
	this->type = assign.getType();
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "😽 Waaaaaim ?" << std::endl;
}