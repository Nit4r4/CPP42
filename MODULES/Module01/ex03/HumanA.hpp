/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:02:55 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/07 15:34:42 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA {
	public:
		HumanA(std::string name, Weapon &type);
		~HumanA();
		
		void	attack();
		

	private:
		std::string	_name;
		Weapon	&_weapon; //to the Weapon adress called from the  Weapon class (ref car toujours un weapon)
};

#endif