/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:49:48 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/14 17:49:48 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <climits>
#include <cfloat>
#include "ScalarConverter.hpp"

static inline char	ft_isPosInf(const double &d)
{
	return (d > DBL_MAX);
}

static inline char	ft_isNegInf(const double &d)
{
	return (d < -DBL_MAX);
}

static inline char	ft_isNan(const double &d)
{
	return (d != d);
}

static inline char	ft_isImpossible(const double &d)
{
	return (ft_isNan(d) || ft_isPosInf(d) || ft_isNegInf(d));
}

static inline char	ft_isInvalidFloat(const std::string &rep)
{
	const std::size_t	&fpos = rep.rfind('f');
	const std::size_t	&size = rep.size();
	const char			isSingleF = rep.find('f') == fpos && fpos != std::string::npos;

	return (isSingleF && size > 1 && fpos == size - 1 && rep.find('.') == std::string::npos);
}

static inline char	ft_isCharacter(const std::string &rep)
{
	const std::size_t	&size = rep.size();
	const char			&firstChar = (size > 0 ? rep[0] : 0);

	return ((size == 1 && ((firstChar >= 32 && firstChar < '0') || (firstChar > '9' && firstChar < 127)))
		|| (size == 2 && firstChar >= '0' && firstChar <= '9' && rep[1] == 'c'));
}

void	ScalarConverter::convert(const std::string &rep)
{
	const double	d = (ft_isInvalidFloat(rep) ? .0/0. : (ft_isCharacter(rep) ? static_cast<int>(rep[0]) : std::strtod(rep.c_str(), 0)));
	const float		f = static_cast<float>(d);
	const int		i = static_cast<int>(d);

	if (i >= 32 && i < 127)
		std::cout << "char: " << static_cast<char>(i) << '\n';
	else if (ft_isImpossible(d) || i > CHAR_MAX || i < CHAR_MIN)
		std::cout << "char: impossible\n";
	else
		std::cout << "char: Non displayable\n";

	if (ft_isImpossible(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << i << '\n';

	if (d > FLT_MAX)
		std::cout << "float: +inff\n";
	else if (d < -FLT_MAX)
		std::cout << "float: -inff\n";
	else if (ft_isNan(d))
		std::cout << "float: nanf\n";
	else
	{
		std::cout << "float: " << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f\n";
	}

	if (ft_isPosInf(d))
		std::cout << "double: +inf" << std::endl;
	else if (ft_isNegInf(d))
		std::cout << "double: -inf" << std::endl;
	else if (ft_isNan(d))
		std::cout << "double: nan" << std::endl;
	else
	{
		std::cout << "double: " << d;
		if (d == static_cast<int>(d))
			std::cout << ".0";
		std::cout << std::endl;
	}
}
