/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:00:49 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/13 09:37:09 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
	public :
		Cat();
		~Cat();
		Cat(Cat const &copy);
		Cat	&operator=(Cat const &assign);

		virtual void	makeSound();

		void		setIdea(std::string idea, int i) const;
		std::string	getIdea(int i) const;
		
	private :
		Brain*	_brain;
};

#endif