/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:21:04 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/04/09 11:02:08 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdio>

int	main(int c, char *v[])
{
	if (c == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (--c + (0 * (long)--*++v)) // Optimized by compiler (no calculation)
		while (*++*v)
			std::putchar(std::toupper(**v)); // Faster than std::cout
	std::putchar('\n'); // Faster than std::cout but does not flush stdout
}
