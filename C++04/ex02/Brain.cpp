/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:33:22 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/20 14:33:23 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for (char i = 0; i < 100; i++)
		*(ideas + i) = "";
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain &cpy)
{
	for (char i = 0; i < 100; i++)
		*(ideas + i) = *(cpy.ideas + i);
	std::cout << "Brain copy constructor called\n";
}

Brain	&Brain::operator=(const Brain &cpy)
{
	for (char i = 0; i < 100; i++)
		*(ideas + i) = *(cpy.ideas + i);
	std::cout << "Brain copy assignment operator called\n";
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called\n";
}

void		Brain::addIdea(const std::string &idea)
{
	for (char i = 0; i < 100; i++)
	{
		if (*(ideas + i) == "")
		{
			*(ideas + i) = idea;
			return ;
		}
	}
	std::cout << "[ERROR] This Brain knows too much about its world... Try replacing a slot.\n";
}

void		Brain::addIdea(const std::string &idea, char slot)
{
	if (slot < 0)
		std::cout << "[ERROR] A Brain can't have " << (int)slot << " ideas... Are you dumb?\n";
	else if (slot > 99)
		std::cout << "[ERROR] A Brain can't have " << (int)slot + 1 << " ideas... Are you crazy?\n";
	else
		*(ideas + slot) = idea;
}

std::string	Brain::readThought(char slot) const
{
	if (slot < 0 || slot > 99)
		return ("");
	return (*(ideas + slot));
}
