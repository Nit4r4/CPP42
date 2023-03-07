/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:24:19 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/07 11:25:04 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
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

DiamondTrap::DiamondTrap(DiamondTrap const &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {
	*this = copy;
	std::cout << getName() << "Copy constructor of DiamondTrap called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &assign) {
	// if (this != &assign) {
	// 	getName() = assign.getName();
	// 	_life = assign._life;
	// 	_energy = assign._energy;
	// 	_damage = assign._damage;
	// }
	ClapTrap::operator = (assign);
	this->FragTrap::operator = (assign);
	this->ScavTrap::operator = (assign);
	std::cout << getName() << "Assignment constructor of DiamondTrap called" << std::endl;
	return *this;
}

// DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
//     if (this != &other) {
//         ClapTrap::operator=(other);
//         getName() = other.getName();
//         _life = other._life;
//         _energy = other._energy;
//         _damage = other._damage;
//     }
//     return *this;
// }

DiamondTrap::~DiamondTrap() {
	std::cout << "ClapTrap : " << getName() << " died like a Diamond" << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << "My name is " << getName() << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

void	DiamondTrap::getInfos() {
	std::cout << "Life or HP like a boss : " << _life << std::endl;
	std::cout << "My energy is like : " << _energy << std::endl;
	std::cout << "I took some damage : " << _damage << std::endl;
}