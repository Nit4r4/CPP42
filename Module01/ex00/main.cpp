/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:04 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/03 08:23:03 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	randomChump("Flag");
	randomChump("Conehead");
	randomChump("Buckethead");
	randomChump("Newspaper");

	Zombie *Zomboni = newZombie("Zamboni");
	Zomboni->announce();
	Zombie *Ducky = newZombie("Ducky Tube");
	Ducky->announce();

	delete Zomboni;
	delete Ducky;
}