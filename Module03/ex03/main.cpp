/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:08:23 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/07 11:10:45 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main() {
	ClapTrap	ct1("CL4P-TP");
	ScavTrap	st2("SC4V-TP");
	FragTrap	ft3("FR4G-TP");
	DiamondTrap	dt4("D14M0ND-TP");
	//ScavTrap* dt4 = new DiamondTrap();
	
	
	
	std::cout << "\n" << std::endl;

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

	st2.attack("a Skag");
	st2.takeDamage(2);
	st2.takeDamage(1);
	st2.beRepaired(3);
	st2.attack("a Skag");
	st2.takeDamage(5);
	st2.beRepaired(3);
	st2.guardGate();
	st2.takeDamage(200);
	
	std::cout << "\n" << std::endl;

	ft3.highFivesGuys();
	ft3.attack("BNK-3R");
	ft3.takeDamage(2);
	ft3.takeDamage(1);
	ft3.beRepaired(3);
	ft3.highFivesGuys();
	ft3.takeDamage(5);
	ft3.beRepaired(3);
	ft3.highFivesGuys();
	ft3.takeDamage(150);
	
	std::cout << "\n" << std::endl;
	
	//dt4->highFivesGuys();
	dt4.attack("Rihanna");
	dt4.whoAmI();
	dt4.getInfos();
	std::cout << "\n" << std::endl;

	return 0;
}