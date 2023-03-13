/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:02:42 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/13 15:37:10 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
std::cout << " " << std::endl;
std::cout << "  ####   #####   #####         ##   ##   ####   #####   ##  ##  ##      ######            ##        ######  ##  ##   ####     ####         " << std::endl;
std::cout << " ##  ##  ##  ##  ##  ##        ### ###  ##  ##  ##  ##  ##  ##  ##      ##            ##  ##        ##       ####   ##  ##   ##  ##        " << std::endl;
std::cout << " ##      #####   #####         ## # ##  ##  ##  ##  ##  ##  ##  ##      ####          ######        ####      ##    ######   ######        " << std::endl;
std::cout << " ##  ##  ##      ##            ##   ##  ##  ##  ##  ##  ##  ##  ##      ##                ##        ##       ####   ##  ##   ##  ##        " << std::endl;
std::cout << "  ####   ##      ##            ##   ##   ####   #####    ####   ######  ######            ##        ######  ##  ##   ####     ####         " << std::endl;
std::cout << " " << std::endl;

	/* Basic tests */
	std::cout << "*** SUBJECTS'S TESTS ***" << std::endl;
	std::cout << " " << std::endl;
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl; 
	std::cout << i->getType() << " " << std::endl; 
	i->makeSound(); //will output the cat sound! 
	j->makeSound();
	meta->makeSound();
	std::cout << " " << std::endl;

	/* Other tests */
	std::cout << "*** SOME MORE TESTS ***" << std::endl;
	std::cout << " " << std::endl;
	
	std::cout << meta->getType() << " " << std::endl;
	
	(*i).makeSound();
	(*j).makeSound();
	(*meta).makeSound();
	std::cout << " " << std::endl;
	std::cout << "adresse de meta : " << meta << " " << std::endl;
	std::cout << "adresse de i : " << i << " " << std::endl;
	std::cout << "adresse de j : " << j << " " << std::endl;

	std::cout << " " << std::endl;

	const Animal* test = new(Cat); //autre maniere d ecrire
	std::cout << " " << std::endl;

	/* Wrong Class tests */
	std::cout << "*** WRONG CLASSES TESTS ***" << std::endl;
	std::cout << " " << std::endl;
	const WrongAnimal* atem = new WrongAnimal(); 
	const WrongAnimal* w = new WrongCat();
	std::cout << " " << std::endl;

	std::cout << atem->getType() << " " << std::endl; 
	std::cout << w->getType() << " " << std::endl;
	std::cout << " " << std::endl;
	//std::cout << "atem : " << atem << std::endl; //will output the wrong animal sound! 
	std::cout << "WRONG ANIMAL atem->makeSound() : " << ""; //will output the wrong animal sound! 
	atem->makeSound();
	std::cout << " " << std::endl;
	std::cout << "WRONG CAT w->makeSound() : " << "";//will output the wrong animal sound! (virtual has been removed from the destructor)
	w->makeSound();
	std::cout << " " << std::endl;
	// std::cout << "WRONG ANIMAL atem->makeSound() : " << std::endl; //will output the wrong animal sound! 
	// atem->makeSound();
	// std::cout << " " << std::endl;
	// std::cout << "WRONG CAT w->makeSound() : " << std::endl;//will output the wrong animal sound! (virtual has been removed from the destructor)
	// w->makeSound();
	// std::cout << " " << std::endl;

	/* Destructors */
	delete w;
	delete atem;
	delete test;
	delete i;
	delete j;
	delete meta;

	return 0;
}

/*************** ****INFO************************
** Le constructeur d’une sous classe invoque   *
** toujours le constructeur de la super classe */