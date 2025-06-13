/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:04:32 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/21 16:04:32 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (char i = 0; i < 4; i++)
		*(_slot + i) = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &cpy)
{
	for (char i = 0; i < 4; i++)
	{
		if (*(_slot + i))
			delete (*(_slot + i));
		if (*(cpy._slot + i))
			*(_slot + i) = (*(cpy._slot + i))->clone();
		else
			*(_slot + i) = NULL;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &cpy)
{
	for (char i = 0; i < 4; i++)
	{
		if (*(_slot + i))
			delete (*(_slot + i));
		if (*(cpy._slot + i))
			*(_slot + i) = (*(cpy._slot + i))->clone();
		else
			*(_slot + i) = NULL;
	}
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (char i = 0; i < 4; i++)
		if (*(_slot + i))
			delete (*(_slot + i));
	std::cout << "MateriaSource destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (char i = 0; i < 4; i++)
	{
		if (!*(_slot + i))
		{
			*(_slot + i) = m;
			std::cout << "* A MateriaSource learned " << m->getType() << " *" << std::endl;
			return ;
		}
	}
	std::cout << "* Greedy guys tried to overclock a MateriaSource *" << std::endl;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (char i = 0; i < 4; i++)
		if (*(_slot + i) && (*(_slot + i))->getType() == type)
			return ((*(_slot + i))->clone());
	return (NULL);
}
