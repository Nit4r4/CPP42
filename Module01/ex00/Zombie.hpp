#ifndef ZOMBIE_HPP
# define ZOMNIE_HPP

# include <iostream>

# define YO "BraiiiiiiinnnzzzZ"

class Zombie
{
	public:
		Zombie(std::string name) :_name(name)
		{
			std::cout << this->_name << std::endl;
		}
		
		~Zombie()
		{

		}

	private:
	
	std::string	_name;

	void	announce(void);

}


#endif