/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:13:10 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/13 09:38:57 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : AAnimal() {
	std::cout << "Cat wakes up 🐈" << std::endl;
	type = "Cat";
	_brain = new Brain;
}

Cat::~Cat(){
		std::cout << "💤 Cat returns to sleep" << std::endl;
		delete _brain;
}

Cat::Cat(Cat const &copy) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = NULL;
	//this->type = copy.getType();
	*this = copy;
}

Cat	& Cat::operator=(Cat const &assign) {
	std::cout << "Cat assignement constructor called" << std::endl;
	//this->type = assign.getType();
	if (this != &assign)
	{
		AAnimal::operator=(assign);
		if (_brain)
			delete _brain;
		_brain = new Brain;
		_brain->operator=(*assign._brain); // copie profonde == duplique le contenu pointé pas seulement le pointeur
	}
	return *this;
}

void	Cat::makeSound() {
	std::cout << "😽 Miaaaaaw" << std::endl;
}

void Cat::setIdea(std::string idea, int i) const {
	if (i < 0 || i > NB_ID)
	{
		std::cout << "Not an available entry" << std::endl;
		return;
	}
	_brain->ideas[i] = idea;
	std::cout << "Cat idea number " << i << std::endl;
}

std::string Cat::getIdea(int i) const {
	if (i < 0 || i > NB_ID)
		return ("Not an available entry");
	return (_brain->ideas[i]);
}
