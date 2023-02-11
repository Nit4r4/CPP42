/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:00:08 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/11 17:57:49 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed() {
	fileName.open(filename);
	newFile.open(filename.append(".replace"));
}

Sed::~Sed() {
	fileName.close();
	newFile.close();
}

// ouvrir filename("textGen");
/*copier son contenu dans filename + ".replace"
en modifiant les occurances passees en arguments lors de l execution s1 = s2 ;
gerer les erreurs : nbr arg, fichier ne s ouve pas, fichier vide, */

void	ft_pos(std::string filename, std::string s1, std::string s2) {
	std::string		read;
	std::size_t		posFound;
	
	while (std::getline(filename, read))
	{
		posFound = read.find(s1, 0);
		while (posFound != std::string::npos)
		{
			read.erase(posFound, s1.length());
			read.insert(posFound, s2);
			posFound = read.find(s1, posFound + 1);
		}
		Sed->newFile << read << std::endl;
		read.clear();
	}
}

std::ifstream newFile(filename + ".replace", std::ifstream::binary);
  if (newFile) {
    // get length of file:
    newFile.seekg (0, newFile.end);
    int length = newFile.tellg();
    newFile.seekg (0, newFile.beg);

    char * buffer = new char [length];

    std::cout << "Reading " << length << " characters... ";
    // read data as a block:
    newFile.read (buffer,length);

    if (newFile)
      std::cout << "all characters read successfully.";
    else
      std::cout << "error: only " << newFile.gcount() << " could be read";
    newFile.close();

    // ...buffer contains the entire file...

    delete[] buffer;
  }

void	ft_swap(int argc, char **argv)

void	ft_replace(std::string filename, std::string s1, std::string s2) {
	std::string	temp;
	if (!filename.empty()) {
		//filename.open();
		//lire le fichier copier les lignes trouver le/s position !!! s1 
		temp = filename.getline(filename);
		temp.get(s1.c_str());
		s1 = s2;
		temp.get(s1.c_str())
		// std::istringstream s1 (argv[2]);
		// std::istringstream s2 (argv[3]);

		// s1.swap(s2);

		
		// std::ifstream is(str);     // open file
		// char c;
		// while (is.get(c))          // loop getting single characters
		// std::cout << c;

		// is.close();                // close file

	}
	std::cout <<  EM_ERR << std::endl;
	//return 0;

}
