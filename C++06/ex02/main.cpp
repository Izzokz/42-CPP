/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:24:14 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/14 20:24:14 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <iostream>

#define ITER 100

int	main(void)
{
	for (char i = 0; i < ITER; ++i)
	{
		const Base *const	&randomClass = generate();
		std::cout << "Identify from ptr: ";
		identify(randomClass);
		std::cout << "\nIdentify from ref: ";
		identify(*randomClass);
		std::cout << std::endl;
		delete (randomClass);
	}
	std::cout << std::endl;
}

