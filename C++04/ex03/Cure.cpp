/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:57:10 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/21 10:57:12 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure default constructor called\n";
}

Cure::Cure(const Cure &cpy) : AMateria(cpy)
{
	std::cout << "Cure copy constructor called\n";
}

Cure	&Cure::operator=(const Cure &cpy)
{
	_type = cpy._type;
	std::cout << "Cure copy assignment operator called\n";
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called\n";
}

AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
