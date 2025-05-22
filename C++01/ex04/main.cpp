/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:51:23 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/15 14:51:24 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	search_and_replace(std::ifstream &input, std::ofstream &output,
	const int len, char *sar[2])
{
	char		*tmpbuff = new char[len + 1];
	std::string	from = (std::string)*sar;
	std::string	to = (std::string)*(sar + 1);
	std::string	buffer;
	std::string	finalForm = "";

	input.seekg(0, input.beg);
	input.read(tmpbuff, len);
	*(tmpbuff + len) = 0;
	buffer = tmpbuff;
	delete[] (tmpbuff);
	input.close();
	if (*(*sar))
	{
		std::string::size_type	prev = 0;
		std::string::size_type	n;
		for (n = buffer.find(from, prev); n != std::string::npos; n = buffer.find(from, prev))
		{
			finalForm += buffer.substr(prev, n - prev) + to;
			prev = n + from.length();
		}
		finalForm += buffer.substr(prev);
	}
	else
		finalForm += buffer;
	output << finalForm;
	output.close();
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "This programs takes a filename, a string (to be replaced by), another string.\n";
		return (1);
	}
	std::ifstream	input(*(argv + 1));
	if (!input.is_open())
	{
		std::cout << *(argv + 1) << " can't be opened.\n";
		return (2);
	}
	std::ofstream	output(((std::string)*(argv + 1) + ".replace").c_str(), std::ios::trunc);
	if (!output.is_open())
	{
		std::cout << "We had issue creating " << (std::string)*(argv + 1) + ".replace" << ".\n";
		input.close();
		return (2);
	}
	input.seekg(0, input.end);
	search_and_replace(input, output, input.tellg(), argv + 2);
}
