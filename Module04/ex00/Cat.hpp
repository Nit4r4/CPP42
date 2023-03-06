/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:00:49 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/06 14:27:24 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
	public :
		Cat();
		virtual ~Cat();
		Cat(Cat const &copy);
		Cat	&operator=(Cat const &assign);

		void	makeSound() const;
};

#endif