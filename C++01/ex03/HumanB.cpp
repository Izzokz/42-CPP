/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:38:58 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/06 15:39:00 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->wpn = NULL;
	std::cout << "\e[32;1mHumanB \"" << this->name << "\" Created !\e[0m\n";
}

HumanB::~HumanB(void)
{
	std::cout << "\e[31;1mHumanB \"" << this->name << "\" Deleted !\e[0m\n";
}

void	HumanB::setWeapon(Weapon &wpn)
{
	this->wpn = &wpn;
}

void	HumanB::attack(void)
{
	if (this->wpn)
		std::cout << this->name << " attacks with their " << this->wpn->getType() << '\n';
	else
		std::cout << this->name << " attacks with their fists\n";
}
