/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:00:49 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/09 14:55:40 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
	public :
		Cat();
		~Cat();
		Cat(Cat const &copy);
		Cat	&operator=(Cat const &assign);

		void	makeSound() const;

		void		setIdea(std::string idea, int i) const;
		std::string	getIdea(int i) const;
		
	private :
		Brain*	_brain;
};

#endif