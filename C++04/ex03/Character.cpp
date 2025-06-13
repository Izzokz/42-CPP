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
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const Character &cpy) : ICharacter(cpy)
{
	for (char i = 0; i < 4; i++)
		*(_slot + i) = NULL;
	*this = cpy;
	std::cout << "Character copy constructor called" << std::endl;
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
	std::cout << "Character copy assignment operator called" << std::endl;
	return (*this);
}

Character::~Character(void)
{
	for (char i = 0; i < 4; i++)
		if (*(_slot + i))
			delete (*(_slot + i));
	std::cout << "Character destructor called" << std::endl;
}

const std::string	&Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "* " << getName() << " found a really odd Materia that can't even be used. *" << std::endl;
		return ;
	}
	for (char i = 0; i < 4; i++)
	{
		if (!*(_slot + i))
		{
			*(_slot + i) = m;
			std::cout << "* " << getName() << " equipped " << m->getType() << " *" << std::endl;
			return ;
		}
	}
	std::cout << "* " << getName() << " tried to equip too many Materia. Greed is bad. *" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "* Something terrible happened... or did not... (?) *" << std::endl;
		return ;
	}
	if (*(_slot + idx))
	{
		std::cout << "* " << getName() << " unequipped " << (*(_slot + idx))->getType() << " *" << std::endl;
		*(_slot + idx) = NULL;
	}
	else
		std::cout << "* " << getName() << " seems to look at his Materia's slots *" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "* " << getName() << " tried to invoke a ghost *" << std::endl;
		return ;
	}
	if (*(_slot + idx))
		(*(_slot + idx))->use(target);
	else
		std::cout << "* " << getName() << " tried to call (void *)0 *" << std::endl;
}

AMateria	*Character::collectMateria(int idx) const
{
	if (idx < 0 || idx > 3)
		return (NULL);
	return (*(_slot + idx));
}
