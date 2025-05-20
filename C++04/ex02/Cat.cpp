/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:27:58 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/19 12:27:59 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal()
{
	_brain = new Brain();
	type = "Cat";
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat &cpy) : AAnimal(cpy)
{
	_brain = new Brain(*cpy._brain);
	std::cout << "Cat copy constructor called\n";
}

Cat	&Cat::operator=(const Cat &cpy)
{
	if (this != &cpy)
	{
		delete (_brain);
		_brain = new Brain(*cpy._brain);
		AAnimal::type = cpy.type;
	}
	std::cout << "Cat copy assignment operator called\n";
	return (*this);
}

Cat::~Cat(void)
{
	delete (_brain);
	std::cout << "Cat destructor called\n";
}

void	Cat::makeSound(void) const
{
	std::cout << "Maaww... Maw !\n";
}

Brain	*Cat::getBrain(void) const
{
	return (_brain);
}
