/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:08:23 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/23 15:30:23 by vferraro         ###   ########.fr       */
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
	ct1.takeDamage(8);

	std::cout << "\n" << std::endl;

	ct2.attack("Andsome Jack");
	ct2.takeDamage(2);
	ct2.takeDamage(1);
	ct2.beRepaired(3);
	ct2.takeDamage(5);
	ct2.beRepaired(3);
	ct2.takeDamage(20);
	std::cout << "\n" << std::endl;
	return 0;
}