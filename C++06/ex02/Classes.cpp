/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:24:26 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/14 20:24:26 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include "ft_rand.h"
#include <cstdio>
#include <iostream>

Base	*generate(void)
{
	char	n = ft_rand() % 3;

	if (n == 1)
	{
		std::cout << "Generating A" << std::endl;
		return (new A());
	}
	if (n == 2)
	{
		std::cout << "Generating B" << std::endl;
		return (new B());
	}
	std::cout << "Generating C" << std::endl;
	return (new C());
}

void	identify(const Base *const &p)
{
	identify(*p);
}

void	identify(const Base &p)
{
	try
	{
		return ((void)std::putchar(*(int *)&dynamic_cast<const A &>(p) * 0 + 'A'));
	}
	catch (...) { }

	try
	{
		return ((void) std::putchar(*(int *)&dynamic_cast<const B &>(p) * 0 + 'B'));
	}
	catch (...) { }

	try
	{
		return ((void) std::putchar(*(int *)&dynamic_cast<const C &>(p) * 0 + 'C'));
	}
	catch (...) { }
}
