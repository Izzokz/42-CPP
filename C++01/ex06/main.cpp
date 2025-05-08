/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:37:17 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/08 15:37:18 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	a = Harl();

	if (argc != 2)
		std::cout << "This program needs one argument\n";
	else
		a.complain((std::string)*(argv + 1));
}
