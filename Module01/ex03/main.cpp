/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:04 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/07 15:32:30 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main() {
	{
	Weapon club = Weapon("crude spiked club");

	HumanA	bob("Bob", club);
	bob.attack();
	club.setType("some other type of club"); 
	bob.attack();
	} 
	{
	Weapon club = Weapon("crude spiked club");

	HumanB	jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club"); 
	jim.attack();
	}
	return (0);
}
