/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:25:43 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/20 18:25:44 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{
	std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &cpy)
{
	(void) cpy;
	std::cout << "ICharacter copy constructor called" << std::endl;
}

ICharacter	&ICharacter::operator=(const ICharacter &cpy)
{
	(void) cpy;
	std::cout << "ICharacter copy assignment operator called" << std::endl;
	return (*this);
}

ICharacter::~ICharacter(void)
{
	std::cout << "ICharacter destructor called" << std::endl;
}
