/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:39 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/03 10:55:47 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name) {
	Zombie	*newZombie;

	newZombie = new Zombie;
	if (!newZombie)
		return (NULL);
	newZombie->setName(name);
	return (newZombie);
}