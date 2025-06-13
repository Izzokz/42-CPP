/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:26:02 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/20 18:26:03 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
	std::cout << "IMateriaSource default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &cpy)
{
	(void) cpy;
	std::cout << "IMateriaSource copy constructor called" << std::endl;
}

IMateriaSource	&IMateriaSource::operator=(const IMateriaSource &cpy)
{
	(void) cpy;
	std::cout << "IMateriaSource copy assignment operator called" << std::endl;
	return (*this);
}

IMateriaSource::~IMateriaSource(void)
{
	std::cout << "IMateriaSource destructor called" << std::endl;
}
