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
}
