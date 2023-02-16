/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:19:16 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/15 13:48:11 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Welcome in Harl's complaining word" << std::endl;
}

Harl::~Harl() {
	std::cout << "Harl is tired, Harl has complained too much..." << std::endl;
}

void	Harl::complain(std::string level) {
		
	std::string _levelArray[4] = {"debug", "info", "warning", "error"};

	void	(Harl::*functionPtr[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++) {
		if (level.compare(_levelArray[i]) == 0) {
			(this->*functionPtr[i])();
			return;
		}
	}
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
