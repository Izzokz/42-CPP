/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:26:54 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/23 16:26:54 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iomanip>

int	main(signed ac, char *av[])
{
	try
	{
		BitcoinExchange::setDB("data.csv");
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << "\nNo database provided" << std::endl;
		return (1);
	}
	std::cout << std::setprecision(20);

	while (--ac)
		BitcoinExchange::getExchangeFromFile(*++av);
}

