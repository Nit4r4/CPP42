/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:00:12 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/15 13:57:22 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int	main(void) {
	Harl	harl;
	std::string	complaining;
	std::cout << "Choose your level of complaining" << std::endl;
	std::cin >> complaining;
	while (complaining > "3") {
		std::cout << "Choose a level between 0 and 3 or all" << std::endl;
		std::cin >> complaining;
	}
	while (complaining >= "0" && complaining < "4") {
		if (complaining == "0") {
			harl.complain("debug");
			std::cin >> complaining;
		}
		if (complaining == "1") {
			harl.complain("info");
			std::cin >> complaining;
		}
		if (complaining == "2") {
			harl.complain("warning");
			std::cin >> complaining;
		}
		if (complaining == "3") {
			harl.complain("error");
			std::cin >> complaining;			
		}
	}
	if (complaining == "all") {
		harl.complain("debug");
		harl.complain("info");
		harl.complain("warning");
		harl.complain("error");
	}	
		return 0;
}
