/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:57:30 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/21 10:57:31 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class	Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &cpy);
		Ice	&operator=(const Ice &cpy);
		~Ice(void);
		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};
