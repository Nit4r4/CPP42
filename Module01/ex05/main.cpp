/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:00:12 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/14 16:54:09 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int	main(void) {
	Harl	harl;
	// std::string	complaining;
	// std::cout << "Choose your level of complaining" << std::endl;
	// std::cin >> complaining;
	// if (complaining > "3")
	// 	std::cout << "Choose a level between 0 and 3 or all" << std::endl;
	// if (complaining >= "0" && complaining < "4") {
	// 	if (complaining == "0")
	// 		harl.complain("debug");
	// 	if (complaining == "1")
	// 		harl.complain("info");
	// 	if (complaining == "2")
	// 		harl.complain("warning");
	// 	if (complaining == "3")
	// 		harl.complain("error");
	// }
	// if (complaining == "all") {
		harl.complain("debug");
		harl.complain("info");
		harl.complain("warning");
		harl.complain("error");
		std::cout << "Harl is tired, Harl has complained too much.. Good Bye Silly" << std::endl;
	// }	
		return 0;
}

1: pourquoi pas de constructeur ni destructeur et pourquoi ca segfault ? sinon prendre un autre exemple...