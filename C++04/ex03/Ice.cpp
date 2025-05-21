/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:57:20 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/21 10:57:21 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Ice default constructor called\n";
}

Ice::Ice(const Ice &cpy) : AMateria(cpy)
{
	std::cout << "Ice copy constructor called\n";
}

Ice	&Ice::operator=(const Ice &cpy)
{
	_type = cpy._type;
	std::cout << "Ice copy assignment operator called\n";
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called\n";
}

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
