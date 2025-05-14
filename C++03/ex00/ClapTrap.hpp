/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:08:21 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/14 12:08:21 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	private:
		std::string	_name;
		unsigned int		_hp;
		unsigned int		_ep;
		unsigned int		_dmg;
	public:
		ClapTrap(std::string name);
		~ClapTrap(void);
		ClapTrap(ClapTrap &cpy);
		ClapTrap	&operator=(ClapTrap &cpy);
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
};

#endif
