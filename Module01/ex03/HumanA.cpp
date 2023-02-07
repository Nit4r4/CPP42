/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:52:05 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/07 16:03:49 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &type) : _name(name), _weapon(type) {
	std::cout << ">> \033[36mHuman A aka 'Bob' pop\e[0m <<" << std::endl;
}

HumanA::~HumanA() {
	std::cout << "\e[31mHum, Bob has been killed :\e[0m" << std::endl;
}

void	HumanA::attack() {
			std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
		}

