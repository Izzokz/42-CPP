/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:26:56 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/20 17:33:30 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("UNK")
{
	std::cout << "AAnimal default constructor called\n";
}

AAnimal::AAnimal(const AAnimal &cpy) : type(cpy.type)
{
	std::cout << "AAnimal copy constructor called\n";
}

AAnimal	&AAnimal::operator=(const AAnimal &cpy)
{
	this->type = cpy.type;
	std::cout << "AAnimal copy assignment operator called\n";
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called\n";
}

std::string	AAnimal::getType(void) const
{
	return (type);
}

void		AAnimal::makeSound(void) const
{
	std::cout << "__NO_SOUND__\n";
}
