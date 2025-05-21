/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:41:34 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/21 15:41:35 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_slot[4];
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &cpy);
		MateriaSource	&operator=(const MateriaSource &cpy);
		~MateriaSource(void);
		void		learnMateria(AMateria *m);
		AMateria	*createMateria(const std::string &type);
};
