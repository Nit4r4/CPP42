/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:14:18 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/07 11:16:02 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_life = (100);
	_energy = (50);
	_damage = (20);
	
	std::cout << name << " wildly appeared 👾" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) {
	*this = copy;
	std::cout << getName() << "Copy constructor of ScavTrap called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &assign) {
	// if (this != &assign) {
	// 	getName() = assign.getName();
	// 	_life = assign._life;
	// 	_energy = assign._energy;
	// 	_damage = assign._damage;
	// }
	this->ClapTrap::operator = (assign);
	std::cout << getName() << "Assignment constructor of ScavTrap called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ClapTrap : " << getName() << " died without any consideration 👾" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) { 
		std::cout << "\033[33mClapTrap : " << getName() << " attacks with a lot of class " << target << "\e[0m" << std::endl;
		// getEnergyPoints() -= 1;
		_energy -= 1;
		std::cout << "\e[31m" << target << " looses : " << getAttackDamage() << " points \e[0m" << std::endl;
	}
	else
		std::cout << "ClapTrap : " << getName() << " cannot be healed ! : " << target << " wins this fight" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << getName() << " is the Guardian of Pandora" << std::endl;
}