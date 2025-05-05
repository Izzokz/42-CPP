/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:32:05 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/05 12:32:06 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		i;

	i = 16;
	horde = zombieHorde(i, "Carl");
	while (--i >= 0)
		(horde + i)->announce();
	delete[] horde;
}
