#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define YO ": BraiiiiiiinnnzzzZ..."

class Zombie
{
	public:
		Zombie();
		~Zombie();

		void	announce(void);
		void setName(std::string name);

	private:
	
		std::string	_name;


};

Zombie*	newZombie( std::string name ); //Crée un zombie, lui donne un nom et le retourne afin qu’il puisse être utilisé en dehors de la portée de la fonction.
void	randomChump( std::string name ); //Crée un zombie, lui donne un nom et le fait se présenter.

#endif