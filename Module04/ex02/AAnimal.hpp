/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 08:01:50 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/13 09:32:31 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

# include "Brain.hpp"

class AAnimal {
	public :
		AAnimal();
		virtual ~AAnimal();
		AAnimal(AAnimal const &copy);
		AAnimal	&operator=(AAnimal const &assign);

		std::string	getType(void) const;

		virtual void	makeSound(void) = 0; // *!*

	protected :
		std::string	type;
};

#endif

/*
> *!* Pour faire en sorte qu'une classe de base ne soit pas instanciable directement, <
> on peut utiliser la methode de rendre cette classe de base abstraite en declarant   <
> une (ou plusieurs) methode virtuelle pure !                                         <
*/