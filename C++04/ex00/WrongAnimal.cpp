/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:12:05 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/19 16:12:06 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("UNK")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy) : type(cpy.type)
{
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &cpy)
{
	type = cpy.type;
	std::cout << "WrongAnimal copy assignment operator called\n";
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called\n";
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}

void		WrongAnimal::makeSound(void) const
{
	std::cout << "RAAAWWWR !!!!\n";
}
