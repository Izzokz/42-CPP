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
	static Zombie	*zombs[5] = {newZombie("Carl"), newZombie("Karl"),
		newZombie("Qarl"), newZombie("K4rl"), newZombie("Kalr")};
	int		i;

	randomChump("AB");
	i = -1;
	while (++i < 5)
	{
		(*(zombs + i))->announce();
		delete (*(zombs + i));
	}
	while (++i < 10)
		randomChump("AE");
}
