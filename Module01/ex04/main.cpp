/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:00:12 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/21 15:56:36 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int	main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cout << ARG_ERR << std::endl;
		return (1);
	}

	std::string fileName(argv[1]);
	std::ifstream fileStream(fileName); //open/define file
	std::string	newFile = fileName + ".replace";
	std::string s1(argv[2]); //define word to replace
	std::string s2(argv[3]); //define new word
	

	if ((fileStream || fileStream != 0))
	{
		std::ofstream	newfile(newFile);
		while (getline(fileStream, fileName)) {
			fileName = ft_pos(fileName, s1, s2);
			newfile << fileName << std::endl;
		}
	}
	else
	{
		std::cout << OP_ERR << std::endl;
		return (1);
	}
	if (fileName.length() <= 0) {
		std::cout << EM_ERR << ::std::endl;
	}
	return 0;
}