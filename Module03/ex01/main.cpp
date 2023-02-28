/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:08:23 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/28 15:59:49 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	ClapTrap	ct1("CL4P-TP");
	ScavTrap	st2("SC4V-TP");
	
	ct1.attack("Andsome Jack");
	ct1.takeDamage(2);
	ct1.takeDamage(1);
	ct1.beRepaired(3);
	ct1.takeDamage(5);
	ct1.beRepaired(3);
	//ct1.guardGate();

	for (int i = 0; i < 1; i++)
		ct1.attack("Andsome Jack");
		
	ct1.takeDamage(8);

	for (int i = 0; i < 1; i++)
		ct1.attack("Andsome Jack");
		
	std::cout << "\n" << std::endl;

	st2.attack("Andsome Jack");
	st2.takeDamage(2);
	st2.takeDamage(1);
	st2.beRepaired(3);
	st2.takeDamage(5);
	st2.beRepaired(3);
	st2.guardGate();
	
	for (int i = 0; i < 3; i++)
		st2.beRepaired(1);
		
	st2.takeDamage(20);
	

	for (int i = 0; i < 1; i++)
		st2.beRepaired(1);
		
	std::cout << "\n" << std::endl;
	
	return 0;
}