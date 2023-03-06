/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:01:50 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/06 14:15:05 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
	public :
		Animal();
		~Animal();
		Animal(Animal const &copy);
		Animal	&operator=(Animal const &assign);

		std::string	const getType(void);
		void		setType(const newType);

	protected :
		std::string	type;
};

#endif