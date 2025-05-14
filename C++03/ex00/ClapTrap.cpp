/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:31:03 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/14 12:31:04 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _hp(10), _ep(10), _dmg(0)
{
	this->_name = name;
	std::cout << "\e[32;1mClapTrap default constructor called\e[0m\n";
}

ClapTrap::ClapTrap(const ClapTrap &cpy) : _name(cpy._name), _hp(cpy._hp), _ep(cpy._ep), _dmg(cpy._dmg)
{
	std::cout << "\e[32;1mClapTrap copy constructor called\e[0m\n";
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "\e[31;1mClapTrap destructor called\e[0m\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &cpy)
{
	this->_name = cpy._name;
	this->_hp = cpy._hp;
	this->_ep = cpy._ep;
	this->_dmg = cpy._dmg;
	std::cout << "\e[32;1mClapTrap copy assignment operator called\e[0m\n";
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (!this->_hp)
		std::cout << "ClapTrap " << this->_name << " tried to attack but is dead... This does not sound logical...\n";
	else if (!this->_ep)
		std::cout << "ClapTrap " << this->_name << " tried to attack but has no energy left.\n";
	else
	{
		this->_ep--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_dmg << " points of damage!\n";
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_hp)
		std::cout << "ClapTrap " << this->_name << " can't take damage anymore because it is already dead...\n";
	if (amount > this->_hp)
		this->_hp = 0;
	else
		this->_hp -= amount;
	std::cout << "ClapTrap " << this->_name << "'s under attack. Hit ! Took " << amount << "DMG ! ";
	if (this->_hp)
		std::cout << this->_hp << "HP remaining.\n";
	else
		std::cout << this->_name << " is dead.\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_hp)
		std::cout << "ClapTrap " << this->_name << " tried to repair itself but is dead... This does not sound logical...\n";
	else if (!this->_ep)
		std::cout << "ClapTrap " << this->_name << " tried to repair itself but has no energy left.\n";
	else
	{
		this->_hp += amount;
		this->_ep--;
		std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << "HP. " << this->_hp << "HP remaining.\n";
	}
}
