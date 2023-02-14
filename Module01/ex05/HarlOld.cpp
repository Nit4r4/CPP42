/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:19:16 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/14 16:41:09 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Harl::Harl() {
// 	std::cout << "Welcome in Harl's complaining word" << std::endl;
// }

// Harl::~Harl() {
// 	std::cout << "Harl is tired, Harl has complained too much.. Good Bye Silly" << std::endl;
// }

void	Harl::complain(std::string level) {
	std::string	_levelArray[4] = {
		_levelArray[0] = "debug",
		_levelArray[1] = "info",
		_levelArray[2] = "warning",
		_levelArray[3] = "error"
	};
	
void	(Harl::*functionPtr[])(void) = {
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error
};

int	i = -1;

while (i < 4)
{
	if (level.compare(_levelArray[i]) == 0)
		i++;
	(this->*functionPtr[i])();
}
std::cout << "error : out of array" << std::endl;
}

void	Harl::debug() {
	std::cout << DEBUG << std::endl;
}

void	Harl::info() {
	std::cout << INFO << std::endl;
}

void	Harl::warning() {
	std::cout << WARNING << std::endl;
}

void	Harl::error() {
	std::cout << ERROR << std::endl;
}
