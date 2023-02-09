/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:44:04 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/07 10:03:41 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(){
	std::string	hi = "HI THIS IS BRAIN";
	std::string	*stringPTR = &hi;
	std::string	&stringREF = hi;

	std::cout << "AFFICHE L'ADDRESSE" << std::endl;
	std::cout << "\e[35mL'adresse de la string en mémoire : " << &hi << std::endl;
	std::cout << "\e[32mL'adresse stockée dans stringPTR : " << stringPTR << std::endl;
	std::cout << "\033[34mL'adresse stockée dans stringREF : " << &stringREF << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "\e[39m* * * * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "AFFICHE LA VALEUR" << std::endl;
	std::cout << "\e[35mLa valeur de la string : " << hi << std::endl;
	std::cout << "\e[32mLa valeur pointée par stringPTR : " << *stringPTR << std::endl;
	std::cout << "\033[34mLa valeur pointée par stringREF : " << stringREF << std::endl;
	std::cout << "\n" << std::endl;

	return (0);
}