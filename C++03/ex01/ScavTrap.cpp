/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:33:42 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/14 15:33:43 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_hp = 100;
	this->_ep = 50;
	this->_dmg = 20;
	std::cout << "\e[33;1mScavTrap default constructor called\e[0m\n";
}

ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy)
{
	this->_name = cpy._name;
	this->_hp = cpy._hp;
	this->_ep = cpy._ep;
	this->_dmg = cpy._dmg;
	std::cout << "\e[33;1mScavTrap copy constructor called\e[0m\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "\e[33;1mScavTrap destructor called\e[0m\n";
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &cpy)
{
	this->_name = cpy._name;
	this->_hp = cpy._hp;
	this->_ep = cpy._ep;
	this->_dmg = cpy._dmg;
	std::cout << "\e[33;1mScavTrap copy assignment operator called\e[0m\n";
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (!this->_hp)
		std::cout << "ScavTrap " << this->_name << " tried to attack but is dead... That's all...\n";
	else if (!this->_ep)
		std::cout << "ScavTrap " << this->_name << " tried to attack but has no energy left.\n";
	else
	{
		this->_ep--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_dmg << "DMG!\n";
	}
}

void	ScavTrap::guardGate(void)
{
	if (!this->_hp)
		std::cout << "ScavTrap " << this->_name << " tried to change mode but is dead... This is logical.\n";
	else
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode.\n";
}
