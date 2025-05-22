/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:10:55 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/05 17:10:57 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	std::cout << "\e[32;1mWeapon Created !\e[0m\n";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
	std::cout << "\e[32;1mWeapon \"" << this->type << "\" Created !\e[0m\n";
}

Weapon::~Weapon(void)
{
	std::cout << "\e[31;1mWeapon \"" << this->type << "\" Deleted !\e[0m\n";
}

const std::string	&Weapon::getType(void) const
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
