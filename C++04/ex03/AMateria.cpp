/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:25:13 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/20 18:25:16 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : _type(type)
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &cpy) : _type(cpy._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &cpy)
{
	_type = cpy._type;
	std::cout << "AMateria copy assignment operator called" << std::endl;
	return (*this);
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

const std::string	&AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* " << target.getName() << " senses a subtle mana touch that feels pretty chill *" << std::endl;
}
