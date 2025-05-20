/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:28:11 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/19 12:28:12 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class	Dog : public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog(void);
		Dog(const Dog &cpy);
		Dog	&operator=(const Dog &cpy);
		virtual ~Dog(void);
		void	makeSound(void) const;
		Brain	*getBrain(void) const;
};
