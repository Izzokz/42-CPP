/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:25:58 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/20 18:25:58 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class	IMateriaSource
{
	public:
		IMateriaSource(void);
		IMateriaSource(const IMateriaSource &cpy);
		IMateriaSource	&operator=(const IMateriaSource &cpy);
		virtual ~IMateriaSource(void);
		virtual void		learnMateria(AMateria *m) = 0;
		virtual AMateria	*createMateria(const std::string &type) = 0;
};
