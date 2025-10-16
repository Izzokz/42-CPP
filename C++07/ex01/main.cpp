/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:52:01 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/16 11:52:01 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include "iter.hpp"

static inline void ft_putchar(const char &c)
{
    std::cout << c << '\n';
}

static inline int printString(const std::string &s)
{
    std::cout << s << '\n';
    return (1);
}

static inline void toUpperCase(std::string &str)
{
    std::transform(str.begin(), str.end(), str.begin(),
              ::toupper);
}

int	main(void)
{
	const std::string	a[3] = {"abc", "def", "ghi"};
	std::string			b[3] = {"abC", "def", "gHi"};
	const char			c[11] = "0123456789";

	iter(a, 3, printString);
	iter(b, 3, printString);
	iter(b, 3, toUpperCase);
	iter(b, 3, printString);
	iter(c, 10, ft_putchar);
}
