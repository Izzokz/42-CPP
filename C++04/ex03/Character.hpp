/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:37:46 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/21 15:37:47 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:
		AMateria	*_slot[4];
		std::string	_name;
	public:
		Character(const std::string &name);
		Character(const Character &cpy);
		Character	&operator=(const Character &cpy);
		~Character(void);
		const std::string	&getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
};
