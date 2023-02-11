/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:00:12 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/11 18:40:05 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

// int	main(int argc, char **argv) {
// 	if (argc != 4)
// 		std::cout << ARG_ERR << std::endl;

// 	std::ifstream fileName(argv[1]); //open/define file
// 	std::istringstream s1 (argv[2]); //define word to replace
// 	std::istringstream s2 (argv[3]); //define new word

// 	s1.swap(s2);
// 	fileName.close();
// 	std::string	newFile = fileName + ".replace";
// 	std::ofstream	fileOf(newFile);
// 	if (!newFile.open())
// 		std::cout << OP_ERR << std::endl;
// 	newFile.close();
// 	return 0;
// }

int	main(int argc, char **argv) {
	if (argc != 4)
		std::cout << ARG_ERR << std::endl;

	std::ifstream fileName(argv[1]); //open/define file
	std::istringstream s1 (argv[2]); //define word to replace
	std::istringstream s2 (argv[3]); //define new word

	ft_pos(fileName, s1, s2);
	std::string	newFile = fileName + ".replace";
	std::ofstream	fileOf(newFile);
	if (!std::string fileOf.is_open())
		std::cout << OP_ERR << std::endl;
	fileOf.is_close();
	return 0;
}