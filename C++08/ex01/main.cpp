/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:56:50 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/18 19:56:50 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

#define BIGNO 696969

int	main(void)
{
	Span	sp = Span(5);

	sp.addNumber(6);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	sp.addNumber(3);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	sp.addNumber(17);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	sp.addNumber(9);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try
	{
		sp.addNumber(1100);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span::const_iterator	it = sp.begin();
	std::cout << "[BEHAVIOUR] Span::shortestSpan() and Span::longestSpan() use Span::sort() so the order changes." << std::endl;
	std::cout << "SIZE: " << (std::size_t)(sp.end() - it) << "\nFIRST ELEMENT: " << *it << "\nTHIRD ELEMENT: " << it[2];
	std::cout << "\nADDR: " << &*it << " VAL: " << it[0];
	std::cout << "\nADDR: " << &*(++it += 3) << " VAL: " << (--(it -= 3))[4] << std::endl;
/*
	std::cout << it[-1] << std::endl; // Error expected
	std::cout << it[-10] << std::endl; // Error expected
*/
	std::cout << (it + 16)[-13] << std::endl;

	Span	nosp;

	try
	{
		nosp.addNumber(1);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << nosp.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << nosp.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span	bigSPAN(BIGNO);
	for (unsigned int i = 2; i < BIGNO; ++i)
		bigSPAN.addNumber(i);
	std::cout << "ADD FINISHED" << std::endl;

	for (int i = 100; i; --i)
	{
		std::cout << bigSPAN.shortestSpan();
		std::cout << bigSPAN.longestSpan();
	}
	std::cout << std::endl;
	bigSPAN.addNumber(2);
	for (int i = 100; i; --i)
	{
		std::cout << bigSPAN.shortestSpan();
		std::cout << bigSPAN.longestSpan();
	}
	std::cout << std::endl;
	bigSPAN.addNumber(-1U / 2);
	for (int i = 100; i; --i)
	{
		std::cout << bigSPAN.shortestSpan();
		std::cout << bigSPAN.longestSpan();
	}
	std::cout << std::endl;

	Span	bigSPANBis(BIGNO);

	try
	{
		bigSPANBis.assign(bigSPAN.begin(), bigSPAN.end());
		std::cout << bigSPANBis.shortestSpan() << std::endl;
		std::cout << bigSPANBis.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span	notBigSPAN(BIGNO - 1);

	try
	{
		notBigSPAN.assign(bigSPAN.begin(), bigSPAN.end());
		std::cout << notBigSPAN.shortestSpan() << std::endl;
		std::cout << notBigSPAN.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		try
		{
			std::cout << notBigSPAN.shortestSpan() << std::endl;
			std::cout << notBigSPAN.longestSpan() << std::endl;
			notBigSPAN.assign(bigSPAN.end(), bigSPAN.end());
			std::cout << "SUCCESS" << std::endl;
			notBigSPAN.assign(bigSPAN.end() - 1, bigSPAN.end());
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
