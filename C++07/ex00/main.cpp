/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:11:03 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/16 11:11:03 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <ctime>

int	main(void)
{
	std::srand(std::time(0));
	{
		int			a = 2;
		int			b = 3;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
		std::string	c = "chaine1";
		std::string	d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << '\n' << std::endl;
	}
	{
		char	a = max<char>('a', 33);
		char	b = min<char>('a', 33);

		puts<int>(a, b);
		swap<char>(a, b);
		std::cout << "After swap\n";
		puts<int>(a, b);
	}
	{
		double	a = max<double>('b', .30035);
		double	b = max<double>('b', .30035);

		puts<double>(a, b);
		puts<int>(a, b);
		swap<double>(a, b);
		std::cout << "After swap\n";
		puts<double>(a, b);
		puts<int>(a, b);
	}
	{
		TestClass	a;
		TestClass	b;

		puts<TestClass>(a, b);
		std::cout << "Min : " << min<TestClass>(a, b) << "\nMax : " << max<TestClass>(a, b) << '\n';
		// swap<TestClass>(a, b); // WON'T COMPILE SINCE THERE IS NO TestClass::operator=()
	}
}
