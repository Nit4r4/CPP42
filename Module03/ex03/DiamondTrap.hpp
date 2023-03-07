/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:24:15 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/07 11:19:30 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap { // pour heriter de plusieurs class on met une virgule pour separer les nom de class
	public :
	
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &copy);
		DiamondTrap	&operator=(DiamondTrap const &assign);
		~DiamondTrap();

		void	attack(const std::string &target);
		void	whoAmI();
		void	getInfos();

	private :
		std::string	_name;
};

#endif