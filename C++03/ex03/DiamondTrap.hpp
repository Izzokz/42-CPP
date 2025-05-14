/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:59:19 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/14 16:59:20 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &cpy);
		DiamondTrap	&operator=(const DiamondTrap &cpy);
		~DiamondTrap(void);
		using	ScavTrap::attack;
		void	whoAmI(void);
};

#endif
