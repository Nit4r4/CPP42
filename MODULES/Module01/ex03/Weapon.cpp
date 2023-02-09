/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:19:47 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/07 15:53:08 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	std::cout << "Construction of the " << this->_type << std::endl;
}

Weapon::~Weapon() {
	std::cout << this->_type << " has been destroyed" << std::endl;
	std::cout << "\n" << std::endl;
}

std::string const &Weapon::getType() {
	return this->_type;
}

void Weapon::setType(std::string type) {
	this->_type = type;
}