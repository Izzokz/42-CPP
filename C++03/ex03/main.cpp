/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:50:44 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/14 12:50:45 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	ScavTrap	def("def");
	ClapTrap	nothing("not");
	ScavTrap	defcpy("www");
	FragTrap	bro("bro");
	DiamondTrap	holy("Holy");

	holy.attack("nothing");
	holy.guardGate();
	holy.takeDamage(99);
	holy.whoAmI();
	defcpy = def;
	nothing.attack("def");
	defcpy.takeDamage(111);
	defcpy.beRepaired(111);
	defcpy.attack("nothing");
	def.beRepaired(555);
	def.attack("def");
	def.takeDamage(500);
	def.guardGate();
	def.beRepaired(1);
	def.beRepaired(2);
	def.beRepaired(3);
	def.beRepaired(4);
	def.beRepaired(5);
	def.beRepaired(6);
	def.beRepaired(7);
	def.beRepaired(8);
	def.beRepaired(9);
	def.takeDamage(1000);
	def.attack("nothing");
	def.guardGate();
	bro.highFiveGuys();
	bro.takeDamage(-1);
	bro.highFiveGuys();
	holy.highFiveGuys();
	holy.takeDamage(1);
	holy.whoAmI();
	//nothing.guardGate();
}
