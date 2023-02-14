/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:00:10 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/14 14:04:11 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <string>
# include <iostream>
# include <istream>
# include <sstream>
# include <fstream>

# define ARG_ERR "\e[31merror : the compiler must be followed by <filename> <s1> <s2>\e[0m"
# define OP_ERR "\e[31merror : cannot open file\e[0m"
# define EM_ERR "\e[31merror : file is empty\e[0m"

class Sed {
	public:
		Sed();
		~Sed();

	
	std::ifstream	fileStream;
	std::ofstream	newFile;
	std::string		s1;
	std::string		s2;
};

	std::string	ft_pos(std::string fileLine, std::string s1, std::string s2);

#endif