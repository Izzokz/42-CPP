/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:27:07 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/06 15:27:08 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wpn) : name(name), wpn(wpn)
{
	std::cout << "\e[32;1mHumanA \"" << this->name << "\" Created !\e[0m\n";
}

HumanA::~HumanA(void)
{
	std::cout << "\e[31;1mHumanA \"" << this->name << "\" Deleted !\e[0m\n";
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->wpn.getType() << '\n';
}
