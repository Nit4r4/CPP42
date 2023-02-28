/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:14:21 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/28 11:09:15 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// # include <iostream>
// # include <string> aussi heritees !!

class ScavTrap : public | private ClapTrap {
	public :
		ScavTrap();
		ScavTrap(ScavTrap const &copy);
		ScavTrap	&operator=(ScavTrap const &assign);
		~ScavTrap();

		void attack(const std::string& target); //remettre car change
		void guardGate();
	
	private :
};

#endif