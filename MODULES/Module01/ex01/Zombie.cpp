/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:12 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/03 14:39:30 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	//std::cout << "\n" << "🌻 A Zombie is comming !!! 📢" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->_name << " has been eliminated 🌱" << std::endl;
}

void	Zombie::setName(std::string name) {
	this->_name = name;
}

void	Zombie::announce() {
	std::cout << this->_name << YO << std::endl;
}
