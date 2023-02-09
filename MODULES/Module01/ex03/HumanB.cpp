/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:31:39 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/07 16:03:43 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	std::cout << ">> \033[36mHuman B aka 'Jim' pop\e[0m <<" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "\e[31mOh, Jim has been killed :\e[0m" << std::endl;
}

void HumanB::attack() {
			std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
		}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}