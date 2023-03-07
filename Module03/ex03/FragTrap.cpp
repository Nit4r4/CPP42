/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:52:53 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/07 11:16:20 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "Constructor FT called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_life = (100);
	_energy = (100);
	_damage = (30);
	
	std::cout << name << " friendly appeared 🦾" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) {
	*this = copy;
	std::cout << getName() << "Copy constructor of FragTrap called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &assign) {
	this->ClapTrap::operator = (assign);
	std::cout << getName() << "Assignment constructor of FragTrap called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "ClapTrap : " << getName() << " died with consideration 🦾" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (getEnergyPoints() > 0 && getHitPoints() > 0) { 
		std::cout << "\033[33mClapTrap : " << getName() << " attacks " << target << "\e[0m" << std::endl;
		// getEnergyPoints() -= 1; 
		_energy -= 1;
		std::cout << "\e[31m" << target << " looses : " << getAttackDamage() << " points \e[0m" << std::endl;
	}
	else
		std::cout << "ClapTrap : " << getName() << " cannot be healed ! : " << target << " wins this fight" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (_energy > 0 && _life > 0) { 
		std::cout << "\e[32mClapTrap : " << getName() << " raises its bionic hand to do a high fives !" << "\e[0m" << std::endl;
	}
}