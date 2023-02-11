/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:00:10 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/11 18:38:03 by vferraro         ###   ########.fr       */
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
		Sed(std::string filename, std::string s1_mod, std::string s2_mod);
		~Sed();

	std::ifstream	fileName;
	std::ofstream	newFile;
	std::string		s1;
	std::string		s2;

	private:
};

void	ft_pos(std::string filename, std::string s1, std::string s2);

#endif