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
	char	i;

	i = -1;
	while (++i < 100)
		*(ideas + i) = "";
	std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain &cpy)
{
	char	i;

	i = -1;
	while (++i < 100)
		*(ideas + i) = *(cpy.ideas + i);
	std::cout << "Brain copy constructor called\n";
}

Brain	&Brain::operator=(const Brain &cpy)
{
	char	i;

	i = -1;
	while (++i < 100)
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
	char	i;

	i = -1;
	while (++i < 100 && *(ideas + i) != "")
		;
	if (i == 100)
		std::cout << "[ERROR] This Brain knows too much about its world... Try replacing a slot.\n";
	else
		*(ideas + i) = idea;
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
