/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:14:18 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/02 12:01:55 by vferraro         ###   ########.fr       */
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
	std::cout << _name << "Copy constructor of ScavTrap called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &assign) {
	// if (this != &assign) {
	// 	_name = assign._name;
	// 	_life = assign._life;
	// 	_energy = assign._energy;
	// 	_damage = assign._damage;
	// }
	this->ClapTrap::operator = (assign);
	std::cout << _name << "Assignment constructor of ScavTrap called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ClapTrap : " << _name << " died without any consideration 👾" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_energy > 0 && _life > 0) { 
		std::cout << "\033[33mClapTrap : " << _name << " attacks with a lot of class " << target << "\e[0m" << std::endl;
		_energy -= 1; //Les actions attaquer et réparer coûtent chacune 1 point d’énergie.
		std::cout << "\e[31m" << target << " looses : " << _damage << " points \e[0m" << std::endl;
	}
	else
		std::cout << "ClapTrap : " << _name << " cannot be healed ! : " << target << " wins this fight" << std::endl;
}

void	ScavTrap::guardGate() {
	std::cout << _name << " is the Guardian of Pandora" << std::endl;
}