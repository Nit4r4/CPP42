/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:02:48 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/14 14:04:17 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(){
}

Sed::~Sed() {
}

std::string	ft_pos(std::string fileLine, std::string s1, std::string s2) {
	std::size_t		posFound;
	
		posFound = fileLine.find(s1, 0);
		while (posFound != std::string::npos)
		{
			fileLine.erase(posFound, s1.length());
			fileLine.insert(posFound, s2);
			posFound = fileLine.find(s1, posFound + 1);

		}
	return fileLine;
}