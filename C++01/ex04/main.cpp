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
	int len, char *sar[2])
{
	char	*buffer = new char[len + 1];
	int		strlen;
	int		i;

	if (*(*sar))
	{
		input.seekg(0, input.beg);
		input.read(buffer, len);
		*(buffer + len) = '\0';
		strlen = ((std::string)*sar).length();
		i = 0;
		while (*(buffer + i))
		{
			if (!((std::string)(buffer + i)).compare(0, strlen, (std::string)*sar))
			{
				output << *(sar + 1);
				i += strlen;
			}
			else
			{
				output << *(buffer + i);
				i++;
			}
		}
	}
	input.close();
	output.close();
	delete []buffer;
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
