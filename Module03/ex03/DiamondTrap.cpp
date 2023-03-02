/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:24:19 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/02 14:57:49 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap() {
	// 	DiamondTrap::DiamondTrap() : ClapTrap() {
    // _name = _name;
    // _life = FragTrap::_life;
    // _energy = ScavTrap::_energy;
    // _damage = FragTrap::_damage;
// }
}

DiamondTrap::DiamondTrap(std::string newName) : ClapTrap(newName + "_clap_name") {
	_name = newName;
	FragTrap::_life;
	ScavTrap::_energy;
	FragTrap::_damage;
	// _life = FragTrap::_life;
    // _energy = ScavTrap::_energy;
    // _damage = FragTrap::_damage;
	
	std::cout << newName << " wildly appeared 👾" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy) {
	*this = copy;
	std::cout << _name << "Copy constructor of DiamondTrap called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &assign) {
	// if (this != &assign) {
	// 	_name = assign._name;
	// 	_life = assign._life;
	// 	_energy = assign._energy;
	// 	_damage = assign._damage;
	// }
	ClapTrap::operator = (assign);
	this->FragTrap::operator = (assign);
	this->ScavTrap::operator = (assign);
	std::cout << _name << "Assignment constructor of DiamondTrap called" << std::endl;
	return *this;
}

// DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
//     if (this != &other) {
//         ClapTrap::operator=(other);
//         _name = other._name;
//         _life = other._life;
//         _energy = other._energy;
//         _damage = other._damage;
//     }
//     return *this;
// }

DiamondTrap::~DiamondTrap() {
	std::cout << "ClapTrap : " << _name << " died like a Diamond" << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

	void DiamondTrap::whoAmI() {
		std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
	}