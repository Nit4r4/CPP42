/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 09:37:50 by vferraro          #+#    #+#             */
/*   Updated: 2023/01/17 13:25:45 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	int	i = 0;
	char	str[45] = "shhhhh... I think the students are asleep...";
	//char	*str_maj = "SHHHHH... I THINK THE STUDENTS ARE ASLEEP...";
	
	// std :: cout << toupper(*str) << std :: endl;
	while (str[i])
		i++;
	return i;
	std :: cout << str[i] << std :: endl;
	return 0;
}