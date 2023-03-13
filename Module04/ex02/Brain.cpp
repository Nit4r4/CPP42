/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:14:03 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/09 15:30:23 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	for (int i = 0; i < NB_ID; ++i)
		ideas[i] = "You know nothing...";
	std::cout << "🧠 Brain constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "🤯 Brain destructor called" << std::endl;
}

Brain::Brain(Brain const &copy) {
	std::cout << "Brain constructor copy called" << std::endl;
	*this = copy;
}

Brain	&Brain::operator=(Brain const &assign) {
	std::cout << "Brain assignment constructor called" << std::endl;
	for (int i = 0; i < NB_ID; ++i)
		// this->setIdea(assign.getIdea(i), i);
		ideas[i] = assign.ideas[i];
	return *this;
	}
