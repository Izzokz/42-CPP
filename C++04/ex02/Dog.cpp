/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:28:06 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/19 12:28:07 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AAnimal()
{
	_brain = new Brain();
	type = "Dog";
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog &cpy) : AAnimal(cpy)
{
	_brain = new Brain(*cpy._brain);
	std::cout << "Dog copy constructor called\n";
}

Dog	&Dog::operator=(const Dog &cpy)
{
	if (this != &cpy)
	{
		delete (_brain);
		_brain = new Brain(*cpy._brain);
		AAnimal::type = cpy.type;
	}
	std::cout << "Dog copy assignment operator called\n";
	return (*this);
}

Dog::~Dog(void)
{
	delete (_brain);
	std::cout << "Dog destructor called\n";
}

void	Dog::makeSound(void) const
{
	std::cout << "Wa-Waf! Waaaf!\n";
}

Brain	*Dog::getBrain(void) const
{
	return (_brain);
}
