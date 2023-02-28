/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:08:23 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/28 10:59:03 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	ClapTrap	ct1("CL4P-TP");
	ClapTrap	ct2("Random Hyperion's robot");
	
	ct1.attack("Andsome Jack");
	ct1.takeDamage(2);
	ct1.takeDamage(1);
	ct1.beRepaired(3);
	ct1.takeDamage(5);
	ct1.beRepaired(3);

	for (int i = 0; i < 1; i++)
		ct1.attack("Andsome Jack");
		
	ct1.takeDamage(8);

	for (int i = 0; i < 1; i++)
		ct1.attack("Andsome Jack");
		
	std::cout << "\n" << std::endl;

	ct2.attack("Andsome Jack");
	ct2.takeDamage(2);
	ct2.takeDamage(1);
	ct2.beRepaired(3);
	ct2.takeDamage(5);
	ct2.beRepaired(3);
	
	for (int i = 0; i < 3; i++)
		ct2.beRepaired(1);
		
	ct2.takeDamage(20);
	

	for (int i = 0; i < 1; i++)
		ct2.beRepaired(1);
		
	std::cout << "\n" << std::endl;
	
	return 0;
}