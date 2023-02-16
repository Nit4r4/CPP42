/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferraro <vferraror@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:17:22 by vferraro          #+#    #+#             */
/*   Updated: 2023/02/15 13:46:22 by vferraro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define DEBUG "\e[32m[level 0 : DEBUG] \e[0m I love having extra beyond meat for my 7XL-double-cheese-triple-pickle-special-ketchup (oh hell yeah!) burger. I really do ! (Great, just starving right now)"
# define INFO "\033[34m[level 1 : INFO] \e[0m I cannot believe adding extra BEYOND MEAT costs more money. You didn't put enough BM in my burger ! If you did, I wouldn't be asking for more !"
# define WARNING "\033[33m[level 2 : WARNING] \e[0m I think I deserve to have some extra BM for free. I've been coming for years whereas you started working here since last month."
# define ERROR "\e[31m[level 3 : ERROR] \e[0m This is unacceptable ! I want to speak to the manager now. (asshole level isn't it ?)"

class Harl {
	public:
		Harl();
		~Harl();


	void	complain(std::string level);
	
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		
		std::string	_levelArray[4];
		//std::string	_levelArray[4] = {"debug", "info", "warning", "error"};

};

#endif