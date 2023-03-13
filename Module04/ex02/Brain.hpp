/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:14:15 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/09 15:49:34 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define NB_ID 100

class Brain {
	public :
		Brain();
		virtual ~Brain();
		Brain(Brain const &copy);
		Brain	&operator=(Brain const &assign);

		std::string ideas[NB_ID];
};

#endif