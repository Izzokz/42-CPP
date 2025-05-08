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

int	main(void)
{
	Harl	a = Harl();

	a.complain("INFO");
	a.complain("DEBUG");
	a.complain("WARNING");
	a.complain("ERROR");
	a.complain("NANANANA");
}
