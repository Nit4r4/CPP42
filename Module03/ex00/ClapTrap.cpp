/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:08:36 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/23 15:46:12 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_life(10),
	_energy(10),
	_damage(0) {
	
		std::cout << name << " just pop on the map 🤖" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy) {
	*this = copy;
	std::cout << _name << "Copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &assign) {
	if (this != &assign) {
		_name = assign._name;
		_life = assign._life;
		_energy = assign._energy;
		_damage = assign._damage;
	}
	std::cout << _name << "Assignment constructor called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap : " << _name << " 'Sbiiiiir...' *Sorry, ClapTrap passed away. Now WE can rest in peace mouhahhahhaha.... wait... too soon ?*" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_energy > 0 && _life > 0) { // ClapTrap ne peut exécuter aucune action s’il n’a plus de vie ou d’énergie
		//target = "Andsome Jack"; assigner dans le main
		std::cout << "\033[33mClapTrap : " << _name << " attacks " << target << "\e[0m" << std::endl;
		_energy -= 1; //Les actions attaquer et réparer coûtent chacune 1 point d’énergie.
		std::cout << "\e[31m" << target << " looses : " << _damage << " points \e[0m" << std::endl;
	}
	else
		std::cout << "ClapTrap : " << _name << " needs healing ! : " << target << " win this fight" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	//std::cout << "lifePoints = " << _life << std::endl;
	if (_life > 0) {
		_life -= amount;
	//	std::cout << "lifePoints = " << _life << std::endl;
		if (_life <= 0) {
			std::cout << PURP"ClapTrap : " << _name << " was fatally shot" RESET << std::endl;
			return ;
		}
		std::cout << "ClapTrap : " << _name << " has taken " << amount << " point(s) damage" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy > 0 && _life > 0) { // Bien entendu, ClapTrap ne peut exécuter aucune action s’il n’a plus de vie ou d’énergie. 
		_life += amount; //QuandClapTrap se répare, il regagne <amount> hit points
		_energy -= 1;// Les actions attaquer et réparer coûtent chacune 1 point d’énergie.
		std::cout << "\033[36mClapTrap : " << _name << " feels " << amount << " point(s) much better, ready to fight again for Butt Stallion 🦄✨\e[0m" << std::endl;
	}
	else
		std::cout << "ClapTrap : " << _name << " cannot be healed, sounds like Handsome Jack wins..." << std::endl;
}