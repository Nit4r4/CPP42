/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:02:42 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/13 09:37:59 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"
#define N 4
#define ID 7

int main() {
std::cout << " " << std::endl;
std::cout << "  ####   #####   #####         ##   ##   ####   #####   ##  ##  ##      ######            ##        ######  ##  ##   ####     #####        " << std::endl;
std::cout << " ##  ##  ##  ##  ##  ##        ### ###  ##  ##  ##  ##  ##  ##  ##      ##            ##  ##        ##       ####   ##  ##   ##   ##       " << std::endl;
std::cout << " ##      #####   #####         ## # ##  ##  ##  ##  ##  ##  ##  ##      ####          ######        ####      ##    ######      ###        " << std::endl;
std::cout << " ##  ##  ##      ##            ##   ##  ##  ##  ##  ##  ##  ##  ##      ##                ##        ##       ####   ##  ##    ##           " << std::endl;
std::cout << "  ####   ##      ##            ##   ##   ####   #####    ####   ######  ######            ##        ######  ##  ##   ####    #######       " << std::endl;
std::cout << " " << std::endl;
	
	/* Basic tests */
	std::cout << "*** SUBJECTS'S TESTS ***" << std::endl;

	const AAnimal* j = new Dog(); 
	const AAnimal* i = new Cat();
	std::cout << std::endl << "\033[35mShould contruct : 2 Animals, 2 Brains, 1 Dog and 1 Cat\e[0m" << std::endl << std::endl;
	delete j;
	delete i;

	std::cout << " " << std::endl;

	/* Other tests */
	std::cout << "*** ARRAY TESTS ***" << std::endl;
	std::cout << " " << std::endl;
	
	AAnimal	*aanimals[N];

	std::cout << "Creation of " << N / 2 << "  dogs" << std::endl << std::endl;

	for (int i = 0; i < N / 2; i++)
		aanimals[i] = new Dog();

	std::cout << std::endl << "Creation of " << N / 2 << " cats" << std::endl << std::endl;

	for (int i = N / 2; i < N; i++)
		aanimals[i] = new Cat();

	std::cout << std::endl << "All the called animal make its sound : " << std::endl << std::endl;

	for (int i = 0; i < N; i++)
	{
		std::cout << aanimals[i]->getType() << " Position in array : " << i << " ";
		aanimals[i]->makeSound();
	}

	std::cout << std::endl << "It's time to call back all the animals" << std::endl << std::endl;

	for (int i = 0; i < N; i++)
		delete aanimals[i];
	
	std::cout << " " << std::endl;

	/* Brain Class tests */
	std::cout << "*** BRAIN CLASS TESTS ***" << std::endl;
	std::cout << " " << std::endl;

	const Cat* Yperry = new Cat();
	const Dog* TheDog = new Dog();
	std::cout << std::endl;

	std::cout << " " << std::endl;
	
	/* Set Idea */
	for (int i = 0; i < ID; ++i) {
		Yperry->setIdea("🐈 'I Miaw a cat and I like fish 🐟'", i);
		TheDog->setIdea("🐕 'Mbarf a dog, and I like everything I can eat 🍗'", i);
	}
	std::cout << " " << std::endl;
	
	/* Get Idea */
	const Cat Astrof = *Yperry;
	const Dog Doggy = *TheDog;
	std::cout << " " << std::endl;
	std::cout << "\033[35mCompare infos, must be the same *copy* :\e[0m" << std::endl;
	std::cout << " " << std::endl;
	for (int i = 0; i < ID; ++i) {
		std::cout << Yperry->getIdea(i) << " ID number : " << i << " = " << Astrof.getIdea(i) << " ID number : " << i << std::endl;
		std::cout << TheDog->getIdea(i) << " ID number : "  << i << " = " << Doggy.getIdea(i) << " ID number : " << i << std::endl;
	} 
	std::cout << " " << std::endl;

	/* Destructors */
	delete Yperry;
	delete TheDog;


	return 0;
}
