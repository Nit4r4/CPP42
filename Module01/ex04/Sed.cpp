/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:02:48 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/11 18:12:47 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string filename, std::string s1_mod, std::string s2_mod) {
	fileName.open(filename);
	newFile.open(filename.append(".replace"));
	s1 = s1_mod;
	s2 = s2_mod;
}

Sed::~Sed() {
	fileName.close();
	newFile.close();
}


void	ft_pos(std::string filename, std::string s1, std::string s2) {
	std::string		read;
	std::size_t		posFound;
	
	while (std::getline(filename, read))
	{
		posFound = read.find(s1, 0);
		while (posFound != std::string::npos)
		{
			read.erase(posFound, s1.length());
			read.insert(posFound, s2);
			posFound = read.find(s1, posFound + 1);
		}
		filename << read << std::endl;
		read.clear();
	}
}