/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:03:26 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/07 15:34:47 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB {
	public:
		HumanB(std::string name);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon &weapon);
		
	private:
		std::string	_name;
		Weapon	*_weapon; //pointeur car pas toujours un weapon
};

	#endif