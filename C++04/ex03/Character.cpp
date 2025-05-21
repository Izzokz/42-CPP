/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:37:50 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/21 15:37:51 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name) : ICharacter()
{
	_name = name;
	for (char i = 0; i < 4; i++)
		*(_slot + i) = NULL;
	std::cout << "Character default constructor called\n";
}

Character::Character(const Character &cpy) : ICharacter(cpy)
{
	_name = cpy._name;
	for (char i = 0; i < 4; i++)
	{
		if (*(_slot + i))
			delete (*(_slot + i));
		if (*(cpy._slot + i))
			*(_slot + i) = (*(cpy._slot + i))->clone();
		else
			*(_slot + i) = NULL;
	}
	std::cout << "Character copy constructor called\n";
}

Character	&Character::operator=(const Character &cpy)
{
	_name = cpy._name;
	for (char i = 0; i < 4; i++)
	{
		if (*(_slot + i))
			delete (*(_slot + i));
		if (*(cpy._slot + i))
			*(_slot + i) = (*(cpy._slot + i))->clone();
		else
			*(_slot + i) = NULL;
	}
	std::cout << "Character copy assignment operator called\n";
	return (*this);
}

Character::~Character(void)
{
	for (char i = 0; i < 4; i++)
		if (*(_slot + i))
			delete (*(_slot + i));
	std::cout << "Character destructor called\n";
}

const std::string	&Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	for (char i = 0; i < 4; i++)
	{
		if (!*(_slot + i))
		{
			*(_slot + i) = m;
			std::cout << "* " << getName() << " equipped " << m->getType() << " *\n";
			return ;
		}
	}
	std::cout << "* " << getName() << " tried to equip too many Materia. Greed is bad. *\n";
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "* Something terrible happened... or did not... *\n";
		return ;
	}
	if (*(_slot + idx))
	{
		std::cout << "* " << getName() << " unequipped " << (*(_slot + idx))->getType() << " *\n";
		*(_slot + idx) = NULL;
	}
	else
		std::cout << "* " << getName() << " seems to look at his Materia's slots *\n";
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "* " << getName() << " tried to invoke a ghost *\n";
		return ;
	}
	if (*(_slot + idx))
		(*(_slot + idx))->use(target);
	else
		std::cout << "* " << getName() << " tried to call (void *)0 *\n";
}
