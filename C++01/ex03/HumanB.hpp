/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:32:06 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/06 15:32:07 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	name;
		Weapon		*wpn;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void		setWeapon(Weapon &wpn);
		void		attack(void);
};

#endif
