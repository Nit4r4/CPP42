/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:37:50 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/14 16:57:24 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <locale>

int	main(int argc, char **argv)
{
	int		i;
	char	*str;
	size_t	size;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < argc)
			{
				std::string str(argv[i++]);
				size = 0;
				while (size < str.length())
					std::cout << (char)std::toupper(str[size++]);
			}
			std::cout << std::endl;
	}
	return (0);
}