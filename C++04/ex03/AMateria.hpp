/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:25:19 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/20 18:25:20 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"
class	ICharacter;

class	AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria(const std::string &type);
		AMateria(const AMateria &cpy);
		AMateria	&operator=(const AMateria &cpy);
		virtual ~AMateria(void);
		const std::string	&getType(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};
