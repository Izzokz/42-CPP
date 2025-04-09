/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:21:04 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/04/07 16:21:06 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	std::string	cpy;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (*(++argv))
	{
		cpy = std::string(*argv);
		for (std::string::iterator iter = cpy.begin(); iter != cpy.end(); iter++)
			std::cout << (char)std::toupper(*iter);
	}
	std::cout << '\n';
	return (1);
}
