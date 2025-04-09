/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:02:27 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/04/09 11:02:29 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

char	gEOF = 0;

int	main(void)
{
	std::string	input;
	PhoneBook	page;

	while (!gEOF)
	{
		std::cout << "phone> ";
		if (!std::getline(std::cin, input))
		{
			std::cout << "\e[35;1mEOF found. Exiting program.\e[0m\n";
			return (0);
		}
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			page.add();
		else if (input == "SEARCH")
			page.search();
	}
	return (0);
}
