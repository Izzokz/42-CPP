/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:25:48 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/20 18:25:49 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
class	AMateria;

class	ICharacter
{
	public:
		ICharacter(void);
		ICharacter(const ICharacter &cpy);
		ICharacter	&operator=(const ICharacter &cpy);
		virtual ~ICharacter(void);
		virtual const std::string	&getName(void) const = 0;
		virtual void	equip(AMateria *m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter &target) = 0;
};
