/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:26:34 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/18 16:26:34 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <vector>
#include "easyfind.hpp"

int	main(void)
{
	{
		const std::string	ctn = " abc";
		const int			i = ' ';
		try
		{
			printContainer(ctn);
			easyfind(ctn, i);
			std::cout << "FOUND!" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "No " << i << " in that container" << std::endl;
		}
	}
	{
		const std::string	ctn = "abc\t\ta";
		const int			i = ' ';
		try
		{
			printContainer(ctn);
			easyfind(ctn, i);
			std::cout << "FOUND!" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "No " << i << " in that container" << std::endl;
		}
	}
	{
		const std::vector<int>	ctn;
		const int				i = 9;
		try
		{
			printContainer(ctn);
			easyfind(ctn, i);
			std::cout << "FOUND!" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "No " << i << " in that container" << std::endl;
		}
	}
	{
		std::vector<int>	ctn;
		const int			i = 9;
		ctn.push_back(8);
		ctn.push_back(10);
		try
		{
			printContainer(ctn);
			easyfind(ctn, i);
			std::cout << "FOUND!" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "No " << i << " in that container" << std::endl;
		}
	}
	{
		std::vector<int>	ctn;
		const int			i = 9;
		ctn.push_back(8);
		ctn.push_back(10);
		ctn.push_back(9);
		try
		{
			printContainer(ctn);
			easyfind(ctn, i);
			std::cout << "FOUND!" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "No " << i << " in that container" << std::endl;
		}
	}
	{
		const std::deque<int>	ctn;
		const int				i = 9;
		try
		{
			printContainer(ctn);
			easyfind(ctn, i);
			std::cout << "FOUND!" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "No " << i << " in that container" << std::endl;
		}
	}
	{
		std::deque<int>	ctn;
		const int		i = 9;
		ctn.push_back(8);
		ctn.push_back(10);
		try
		{
			printContainer(ctn);
			easyfind(ctn, i);
			std::cout << "FOUND!" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "No " << i << " in that container" << std::endl;
		}
	}
	{
		std::deque<int>	ctn;
		const int		i = 9;
		ctn.push_back(8);
		ctn.push_back(10);
		ctn.push_back(10 - 1);
		try
		{
			printContainer(ctn);
			easyfind(ctn, i);
			std::cout << "FOUND!" << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "No " << i << " in that container" << std::endl;
		}
	}
}
