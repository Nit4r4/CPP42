#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <stdint.h>
# include <string>

class Data {
	private:
		unsigned int	_data;

	public:
		Data();
		~Data();
		Data(const Data &cpy);
		Data &operator=(const Data &assign);

		void	setData(unsigned int data);
		unsigned int	getData(void) const;
};

uintptr_t	serialize(Data* ptr);
Data*	deserialize(uintptr_t raw);

#endif
