/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:35:35 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/14 19:35:35 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void	printData(const Data *const &d, const std::string &name = "test")
{
	std::cout << name << ":\n";

	std::cout << "  i      = " << d->i << '\n';
	std::cout << "  iP     = " << d->iP << '\n';

	std::cout << "  c      = " << (const int)d->c << '\n';

	std::cout << "  str    = " << d->str << '\n';
	std::cout << "  strPtr = " << d->strPtr << '\n';

	std::cout << std::endl;
}


int	main(void)
{
	Data		test;
	test.i = 19;
	test.iP = &test.i;
	test.c = 99;
	test.str = "PacMan";
	test.strPtr = &test.str;

	uintptr_t	ser = Serializer::serialize(&test);
	Data		*same = Serializer::deserialize(ser);

	std::cout << "test: " << (const void *const &)&test << '\n';
	std::cout << "ser: " << (const void *const &)ser << '\n';
	std::cout << "same: " << (const void *const &)same << '\n';

	printData(&test, "test");
	printData((const Data *const &)ser, "ser");
	printData(same, "same");
}
