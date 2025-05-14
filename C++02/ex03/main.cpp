/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:35:31 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/13 18:35:34 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Increase precision for better results
int	main(void)
{
	Point	a(5.5f, .0f);
	Point	b(5.5f, 1.0f);
	Point	c(9.5f, .5f);
	Point	p1(6.5f, .5f);
	Point	p2(5.501f, .5f);
	Point	p3(7.6f, .499f);
	Point	p4(7.6f, .999f);
	bool	res1;
	bool	res2;
	bool	res3;
	bool	res4;

	res1 = bsp(a, b, c, p1);
	res2 = bsp(a, b, c, p2);
	res3 = bsp(a, b, c, p3);
	res4 = bsp(a, b, c, p4);
	std::cout << "\e[33;1m{ " << res1 << " }\e[0m\n";
	std::cout << "\e[33;1m{ " << res2 << " }\e[0m\n";
	std::cout << "\e[33;1m{ " << res3 << " }\e[0m\n";
	std::cout << "\e[33;1m{ " << res4 << " }\e[0m\n";
	return (0);
}
