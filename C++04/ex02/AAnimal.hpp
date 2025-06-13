/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:27:02 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/20 17:33:36 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.hpp"

class	AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal(void);
		AAnimal(const AAnimal &cpy);
		AAnimal	&operator=(const AAnimal &cpy);
		virtual ~AAnimal(void);
		std::string	getType(void) const;
		virtual void	makeSound(void) const = 0;
		virtual Brain	*getBrain(void) const = 0;
};
