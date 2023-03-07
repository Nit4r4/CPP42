/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:49:04 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/07 11:17:03 by vferraro         ###   ########.fr       */
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
		virtual ~FragTrap();

		void attack(std::string const &target);
		void highFivesGuys(void);
	
};

#endif