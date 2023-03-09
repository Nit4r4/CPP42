/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:02:42 by vferraro          #+#    #+#             */
/*   Updated: 2023/03/09 17:01:51 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"
#define N 4
#define ID 7

int main() {
std::cout << " " << std::endl;
std::cout << "  ####   #####   #####         ##   ##   ####   #####   ##  ##  ##      ######            ##        ######  ##  ##   ####     ##           " << std::endl;
std::cout << " ##  ##  ##  ##  ##  ##        ### ###  ##  ##  ##  ##  ##  ##  ##      ##            ##  ##        ##       ####   ##  ##   ###           " << std::endl;
std::cout << " ##      #####   #####         ## # ##  ##  ##  ##  ##  ##  ##  ##      ####          ######        ####      ##    ######    ##           " << std::endl;
std::cout << " ##  ##  ##      ##            ##   ##  ##  ##  ##  ##  ##  ##  ##      ##                ##        ##       ####   ##  ##    ##           " << std::endl;
std::cout << "  ####   ##      ##            ##   ##   ####   #####    ####   ######  ######            ##        ######  ##  ##   ####   ######         " << std::endl;
std::cout << " " << std::endl;
	
	/* Basic tests */
	std::cout << "*** SUBJECTS'S TESTS ***" << std::endl;

	const Animal* j = new Dog(); 
	const Animal* i = new Cat();
	std::cout << std::endl << "\033[35mShould contruct : 2 Animals, 2 Brains, 1 Dog and 1 Cat\e[0m" << std::endl << std::endl;
	delete j;//should not create a leak 
	delete i;

	std::cout << " " << std::endl;

	/* Other tests */
	std::cout << "*** ARRAY TESTS ***" << std::endl;
	std::cout << " " << std::endl;
	
	Animal	*animals[N];

	std::cout << "Creation of " << N / 2 << "  dogs" << std::endl << std::endl;

	for (int i = 0; i < N / 2; i++)
		animals[i] = new Dog();

	std::cout << std::endl << "Creation of " << N / 2 << " cats" << std::endl << std::endl;

	for (int i = N / 2; i < N; i++)
		animals[i] = new Cat();

	std::cout << std::endl << "All the called animal make its sound : " << std::endl << std::endl;

	for (int i = 0; i < N; i++)
	{
		std::cout << animals[i]->getType() << " Position in array : " << i << " ";
		animals[i]->makeSound();
	}

	std::cout << std::endl << "It's time to call back all the animals" << std::endl << std::endl;

	for (int i = 0; i < N; i++)
		delete animals[i];
	
	std::cout << " " << std::endl;
	

	// const Animal *AnimalTab[10];
	// const Animal* D = new Dog();
	// const Animal* C = new Cat();
	// //WrongAnimal *wrongcat = new WrongCat();

	// for (int i = 0; i < 10; i++){
	// 	if (i % 2)
	// 		AnimalTab[i] = new Dog();
	// 	else
	// 		AnimalTab[i] = new Cat();
	// 	std::cout << "The animal : " << AnimalTab[i]->getType() << " number " << i << std::endl;
	// 	AnimalTab[i]->makeSound();
	// 	std::cout << std::endl;
	// }

	// delete D;
	// delete C;

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

/*************** ****INFO************************
** Le constructeur d’une sous classe invoque   *
** toujours le constructeur de la super classe */