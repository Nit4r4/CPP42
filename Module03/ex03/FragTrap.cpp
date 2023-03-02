/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:52:53 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/02 11:58:42 by vferraro         ###   ########.fr       */
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
	std::cout << _name << "Copy constructor of FragTrap called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &assign) {
	this->ClapTrap::operator = (assign);
	std::cout << _name << "Assignment constructor of FragTrap called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "ClapTrap : " << _name << " died with consideration 🦾" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (_energy > 0 && _life > 0) { 
		std::cout << "\e[32mClapTrap : " << _name << " raises its bionic hand to do a high fives !" << "\e[0m" << std::endl;
	}
}