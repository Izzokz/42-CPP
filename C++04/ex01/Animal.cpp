/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:26:56 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/19 12:26:58 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("UNK")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal &cpy) : type(cpy.type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal	&Animal::operator=(const Animal &cpy)
{
	this->type = cpy.type;
	std::cout << "Animal copy assignment operator called\n";
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called\n";
}

std::string	Animal::getType(void) const
{
	return (type);
}

void		Animal::makeSound(void) const
{
	std::cout << "__NO_SOUND__\n";
}

Brain		*Animal::getBrain(void) const
{
	return (NULL);
}
