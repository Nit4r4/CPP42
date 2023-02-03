/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:04 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/03 14:42:26 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie	*horde;
	Zombie	*walkingHorde;
	
	std::cout << "🧠 Zombies are comming !!! 🧠" << "\n" << std::endl;
	horde = zombieHorde(4, "\033[34mZombie\e[39m");
	walkingHorde = zombieHorde(20, "\e[31mWalker\e[39m");
	delete [] horde;
	delete [] walkingHorde;
	return (0);
}