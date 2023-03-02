/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:49:04 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/02 10:50:40 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public :
	
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &copy);
		FragTrap	&operator=(FragTrap const &assign);
		~FragTrap();

		void highFivesGuys(void);
	
};

#endif