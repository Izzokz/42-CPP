/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:29:50 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/14 16:29:52 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 100;
	this->_dmg = 30;
	std::cout << "\e[34;1mFragTrap default constructor called\e[0m\n";
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy)
{
	this->_hp = cpy._hp;
	this->_ep = cpy._ep;
	this->_dmg = cpy._dmg;
	std::cout << "\e[34;1mFragTrap copy constructor called\e[0m\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "\e[34;1mFragTrap destructor called\e[0m\n";
}

FragTrap	&FragTrap::operator=(const FragTrap &cpy)
{
	this->_name = cpy._name;
	this->_hp = cpy._hp;
	this->_ep = cpy._ep;
	this->_dmg = cpy._dmg;
	std::cout << "\e[34;1mFragTrap copy assignment operator called\e[0m\n";
	return (*this);
}

void	FragTrap::highFiveGuys(void)
{
	if (!this->_hp)
		std::cout << "FragTrap " << this->_name << "> Thanks, you revenge me guys !\n";
	else
		std::cout << "FragTrap " << this->_name << "> Yeah we won !\n";
}
