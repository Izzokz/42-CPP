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
	std::cout << "Before : ";
	fPm.print();
	long									t1 = fPm.sort();
	if (!fPm.isSorted())
		std::cerr << "\033[31;1mfPm is not sorted !\033[0m\n";
	long									t2 = sPm.sort();
	if (!sPm.isSorted())
		std::cerr << "\033[31;1msPm is not sorted !\033[0m\n";
	std::cout << "After : ";
	fPm.print();
	std::cout << "Time to process fPm (std::vector) : " << t1 << "ms.\n";
	std::cout << "Time to process sPm (std::deque) : " << t2 << "ms." << std::endl;
}
