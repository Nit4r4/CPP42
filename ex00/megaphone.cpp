/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:37:50 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/18 11:45:58 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // std::cout
#include <string>  //std::string
#include <locale> // std::toupper

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	size_t	size;
	
	if (argc == 1) // if only ./megaphone
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1; // for argv[1] beacause argv[0] is the executable
		while (i < argc) // while i compteur is under nbr of total arguments
			{
				std::string str(argv[i++]);
				size = 0;
				while (size < str.length())
					std::cout << (char)std::toupper(str[size++]); // need to cast into char or we get int
			}
			std::cout << std::endl;
	}
	return (0);
}