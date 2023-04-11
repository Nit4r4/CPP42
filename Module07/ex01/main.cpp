/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:47:36 by vferraro          #+#    #+#             */
/*   Updated: 2023/04/11 13:14:05 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void) {
	std::cout << "ARRAY OF INT :" << std::endl;
	//std::cout << "\n" << std::endl;
	int arrayI[6] = {0, 1, 2, 32, 4, 65};
	iter(arrayI, 6, ft_call);

	std::cout << "\n" << std::endl;
	std::cout << "ARRAY OF FLOAT :" << std::endl;
	//std::cout << "\n" << std::endl;
	float arrayF[6] = {0.3, 1.32, 2.56, 32.2, 4.6, 65.65};
	iter(arrayF, 6, ft_call);
	
	std::cout << "\n" << std::endl;
	std::cout << "ARRAY OF DOUBLE :" << std::endl;
	//std::cout << "\n" << std::endl;
	double arrayD[6] = {0, 1.32, 2.4, 32.32, 4.4, 65};
	iter(arrayD, 6, ft_call);
	
	std::cout << "\n" << std::endl;
	std::cout << "ARRAY OF CHAR :" << std::endl;
	//std::cout << "\n" << std::endl;
	char arrayC[6] = {'C', 'h', 'a', 'r', '0', '!'};
	iter(arrayC, 6, ft_call);

	std::cout << "\n" << std::endl;
	std::cout << "ARRAY OF STRING :" << std::endl;
	//std::cout << "\n" << std::endl;
	std::string arrayS[3] = {"Zero", "un", "SALUT !"};
	iter(arrayS, 3, ft_call);

	return 0;
}