/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:13:36 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/13 09:39:14 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : AAnimal() {
	std::cout << "Dog wants to play 🐕" << std::endl;
	type = "Dog";
	_brain = new Brain;
}

Dog::~Dog(){
		std::cout << " 🦴 Dog turns back to its doghouse" << std::endl;
		delete _brain;
}

Dog::Dog(Dog const &copy) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = NULL;
	//this->type = copy.getType();
	*this = copy;

}

Dog	& Dog::operator=(Dog const &assign) {
	std::cout << "Dog assignment constructor called" << std::endl;
	if (this != &assign)
	{
		this->AAnimal::operator=(assign);
		if (_brain)
			delete _brain;
		_brain = new Brain;
		this->_brain->operator=(*assign._brain); // copie profonde
	}
	//this->type = assign.getType();
	return *this;
}

void	Dog::makeSound() {
	std::cout << "🐶 Ouaf ouaf" << std::endl;
}

void Dog::setIdea(std::string idea, int i) const {
	if (i < 0 || i > NB_ID)
	{
		std::cout << "Not an available entry" << std::endl;
		return;
	}
	_brain->ideas[i] = idea;
	std::cout << "Dog idea number " << i << std::endl;
}

std::string Dog::getIdea(int i) const {
	if (i < 0 || i > NB_ID)
		return ("Not an available entry");
	return (_brain->ideas[i]);
}