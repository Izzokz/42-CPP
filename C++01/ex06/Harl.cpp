/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:03:24 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/08 15:03:25 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	const char	*levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	char		*actualLevel = (char *)"";
	char		i;

	i = -1;
	while (++i < 4)
		if (level == (std::string)*(levels + i))
			actualLevel = (char *)*(levels + i);
	switch (*actualLevel)
	{
		case 'D':
			this->debug();
		case 'I':
			this->info();
		case 'W':
			this->warning();
		case 'E':
			this->error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
