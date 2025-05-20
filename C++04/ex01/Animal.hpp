/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:27:02 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/19 12:27:03 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Brain.hpp"

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(const Animal &cpy);
		Animal	&operator=(const Animal &cpy);
		virtual ~Animal(void);
		std::string	getType(void) const;
		virtual void	makeSound(void) const;
		virtual Brain	*getBrain(void) const = 0;
};
