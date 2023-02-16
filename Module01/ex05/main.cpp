/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:00:12 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/16 08:48:40 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int	main(void) {
	Harl	harl;
	std::string	complaining;
	std::cout << "Choose your level of complaining between 0 and 4, yes, 4 means all the complaing levels, you can't say I didn't warn you !" << std::endl;
	std::cin >> complaining;
	while (complaining > "4") {
		std::cout << "SERIOUSLY ??? I SAIID : Choose a level between 0 and 4 !" << std::endl;
		std::cin >> complaining;
	}
	while ((complaining >= "0" && complaining <= "4")) {
		if (complaining == "0") {
			harl.complain("debug");
			std::cin >> complaining;
		}
		else if (complaining == "1") {
			harl.complain("info");
			std::cin >> complaining;
		}
		else if (complaining == "2") {
			harl.complain("warning");
			std::cin >> complaining;
		}
		else if (complaining == "3") {
			harl.complain("error");
			std::cin >> complaining;			
		}
		else if (complaining == "4") {
			harl.complain("debug");
			harl.complain("info");
			harl.complain("warning");
			harl.complain("error");
			break;
		}	
	}
		return 0;
}
