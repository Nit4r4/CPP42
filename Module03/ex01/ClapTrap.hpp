/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:08:39 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/28 16:01:57 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define PURP "\e[35m"
# define RESET "\e[0m"

class ClapTrap {
	public :
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap();

		ClapTrap	&operator=(ClapTrap const &assign);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	
	protected : //parce qu en private on ne peut pas l utiliser !!!
		std::string	_name;
		int	_life;
		int	_energy;
		int	_damage;

};

/* LA DIFFERENCE ENTRE L’OPERATEUR D’AFFECTATION ET L’OPERATEUR DE COPIE
Est que le constructeur de copie crée un nouvel objet en copiant les valeurs
d'un objet existant, tandis que l'opérateur d'affectation copie les valeurs
d'un objet existant dans un objet déjà créé */

#endif