/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:14:21 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/02 14:48:31 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// # include <iostream>
// # include <string> aussi heritees !!

class ScavTrap : public ClapTrap {
	public :
	
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &copy);
		ScavTrap	&operator=(ScavTrap const &assign);
		~ScavTrap();

		virtual void attack(const std::string& target); //remettre car change
		void guardGate();
	
};

#endif