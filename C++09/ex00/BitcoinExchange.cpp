/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:26:42 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/23 16:26:42 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>

#define READ_SIZE 1000

std::map<long, float>	BitcoinExchange::_db;

static char	dateExists(const long &formatDate)
{
	int	d = formatDate % 100;
	int	m = (formatDate / 100) % 100;
	int	y = formatDate / 10000;

	if (!m || m > 12 || !d)
		return (0);
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return (d <= 31);
	if (m != 2)
		return (d <= 30);
	if (!(y % 400) || (!(y % 4) && y % 100))
		return (d <= 29);
	else
		return (d <= 28);
	return ((int)(long)dateExists);
}

static long	validDate(const std::string &date)
{
	std::size_t		pos = 0;
	char			i = 0;
	double			formatDate = 0;
	do
	{
		if (++i > 3)
			break ;
		std::size_t	newPos = date.find('-', pos);
		std::string	component = date.substr(pos, newPos - pos);
		std::size_t	csize = component.size();
		if (i - 1)
		{
			if (csize > 2)
				return (0);
		}
		else
			if (csize > 14)
				return (0);
		if ((std::string)(date.c_str() + pos) == component)
		{
			if (i < 3)
				return (0);
		}
		else
			if (i == 3)
				return (0);
		for (std::size_t charCounter = 0; charCounter < csize; ++charCounter)
		{
			if (component[charCounter] < '0' || component[charCounter] > '9')
				return (0);
			formatDate = formatDate * 10 + component[charCounter] - '0';
		}
		pos = newPos + 1;
	} while (1);
	return (dateExists(formatDate) ? formatDate : 0);
}

static inline std::string	readFile(const std::string &file)
{
	const int	fd = open(file.c_str(), O_RDONLY);
	if (fd < 0)
		throw (std::runtime_error("cannot open file"));
	if (read(fd, (void *)0b111010101010011, 0) < 0)
		throw (std::runtime_error("file is dir"));
	std::string	content;
	char		buf[READ_SIZE + 1];
	int			bytesRead;

	do
	{
		bytesRead = read(fd, buf, READ_SIZE);
		if (bytesRead < 0)
			throw (std::runtime_error("read fail"));
		*(buf + bytesRead) = 0;
		content += buf;
	} while (bytesRead);
	return (content);
}

void	BitcoinExchange::setDB(const std::string &datafileName)
{
	std::string				data = readFile(datafileName);

	_db.erase(_db.begin(), _db.end());
	_db[0] = 0;
	std::size_t				pos = data.find('\n') + 1;
	while (1)
	{
		std::size_t			lim = data.find('\n', pos);
		if (lim == std::string::npos)
			return ;
		const std::string	line = data.substr(pos, lim - pos);
		pos = lim + 1;
		lim = line.find(',');
		if (lim == std::string::npos || lim == line.size() - 1)
			continue ;
		const double		formatDate = validDate(line.substr(0, lim));
		const float			value = atof(line.c_str() + lim + 1);
		if (value < 0 || !formatDate)
			continue ;
		_db[formatDate] = value;
	}
}

const std::map<long, float>	&BitcoinExchange::getDB(void)
{
	return (_db);
}

const float	&BitcoinExchange::getCorrespondence(const long &formatDate)
{
	std::map<long, float>::const_iterator	it = _db.lower_bound(formatDate);
	if (it == _db.end())
		--it;
	else if (it->first != formatDate)
	{
		if (it == _db.end())
			return (it->second);
		--it;
	}
	return (it->second);
}

void	BitcoinExchange::getExchange(const std::string &date, const float &n)
{
	if (_db.empty())
		throw (std::runtime_error("empty database"));
	const double	formatDate = validDate(date);
	if (!formatDate)
		throw (std::runtime_error("bad input"));
	if (n < 0)
		throw (std::runtime_error("not a positive number."));
	if (n > 1000)
		throw (std::runtime_error("too large a number."));
	std::cout << date << " => " << n << " = " << getCorrespondence(formatDate) * n << std::endl;
}

void	BitcoinExchange::getExchangeFromFile(const std::string &file)
{
	std::string	data;
	try
	{
		data = readFile(file);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}

	std::size_t				pos = data.find('\n') + 1;
	while (1)
	{
		std::size_t			lim = data.find('\n', pos);
		if (lim == std::string::npos)
			return ;
		const std::string	line = data.substr(pos, lim - pos);
		pos = lim + 1;
		lim = line.find(" | ");
		if (lim == std::string::npos || lim == line.size() - 3)
		{
			std::cout << "bad input (" << line << ')' << std::endl;
			continue ;
		}
		try
		{
			getExchange(line.substr(0, lim), atof(line.c_str() + lim + 3));
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << " (" << line << ')' << std::endl;
		}
	}
}
