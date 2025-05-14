/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:19:53 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/14 17:19:54 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name += "_clap_name";
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_dmg = FragTrap::_dmg;
	std::cout << "\e[35;1mDiamondTrap default constructor called\e[0m\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy) : ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy)
{
	this->_hp = cpy._hp;
	this->_ep = cpy._ep;
	this->_dmg = cpy._dmg;
	std::cout << "\e[35;1mDiamondTrap copy constructor called\e[0m\n";
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "\e[35;1mDiamondTrap destructor called\e[0m\n";
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &cpy)
{
	this->_name = cpy._name;
	this->_hp = cpy._hp;
	this->_ep = cpy._ep;
	this->_dmg = cpy._dmg;
	std::cout << "\e[35;1mDiamondTrap copy assignment operator called\e[0m\n";
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	if (!this->_hp)
		std::cout << "DiamondTrap " << this->_name << " wanted to reminisce itself but is dead so can't... Sad story.\n";
	else
		std::cout << "DiamondTrap " << this->_name << "> Am I " << this->ClapTrap::_name << " ???\n";
}
