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
		void	setName(std::string name);

	private:
	
		std::string	_name;


};

Zombie*	zombieHorde(int N, std::string name);

#endif