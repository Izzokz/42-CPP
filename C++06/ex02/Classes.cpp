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
#include <cstdio>
#include <cstdlib>
#include <iostream>

Base	*generate(void)
{
	char	n = std::rand() % 3;

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
		const A	&transform = dynamic_cast<const A &>(p);
		(void) transform;
		std::putchar('A');
		return ;
	}
	catch (...) { }

	try
	{
		const B &transform = dynamic_cast<const B &>(p);
		(void) transform;
		std::putchar('B');
		return ;
	}
	catch (...) { }

	try
	{
		const C	&transform = dynamic_cast<const C &>(p);
		(void) transform;
		std::putchar('C');
		return ;
	}
	catch (...) { }
}
