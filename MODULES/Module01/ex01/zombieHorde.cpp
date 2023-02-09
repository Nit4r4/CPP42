/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:00:03 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/03 14:35:56 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	Zombie	*newZombie;
	int		i;
	
	newZombie = new Zombie[N];
	i = 0;
	while (i < N) {
		newZombie[i].setName(name + " " + std::to_string(i + 1));
		newZombie[i].announce();
		i++;
	}
	return (newZombie);
}
