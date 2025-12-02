/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:50:24 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/11/27 15:50:24 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <cstdlib>

int	main(int argc, const char *const argv[])
{
	if (argc < 2)
	{
		std::cout << "Waiting for values..." << std::endl;
		return (0);
	}

	PmergeMe<std::vector<unsigned int> >	fPm; // Fast PmergeMe
	PmergeMe<std::deque<unsigned int> >		sPm; // Slow PmergeMe
	while (--argc)
	{
		unsigned int						current = std::atoi(*++argv);
		fPm.add(current);
		sPm.add(current);
	}
	fPm.print();
	sPm.print();
	fPm.sort();
	sPm.sort();
	fPm.print();
	sPm.print();
}
