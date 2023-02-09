/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:07:36 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/07 15:39:21 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
#include <string>

class Weapon {
public:
	Weapon(std::string type);
	~Weapon();
	
	std::string const &getType();
	void		setType(std::string);
	
private:
	std::string	_type;
};

#endif