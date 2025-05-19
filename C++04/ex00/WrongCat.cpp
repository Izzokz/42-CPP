/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:12:21 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/19 16:12:22 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat &cpy) : WrongAnimal(cpy)
{
	type = "WrongCat";
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat	&WrongCat::operator=(const WrongCat &cpy)
{
	WrongAnimal::type = cpy.type;
	std::cout << "WrongCat copy assignment operator called\n";
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called\n";
}

void	WrongCat::makeSound(void) const
{
	std::cout << "MAOUUW!!!\n";
}
