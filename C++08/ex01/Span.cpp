/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:56:13 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/18 19:56:13 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

const Span::NoSpanException			Span::NSE;
const Span::SizeMaxReachedException	Span::SMRE;

Span::Span(void)
{
	_N = 0;
}

Span::Span(const unsigned int &N)
{
	_N = N;
	_ss = -1U;
	_lastSort = 0;
}

Span::Span(const Span &cpy)
{
	_N = cpy._N;
	_vector = cpy._vector;
	_ss = cpy._ss;
	_lastSort = cpy._lastSort;
}

Span	&Span::operator=(const Span &cpy)
{
	_N = cpy._N;
	_vector = cpy._vector;
	_ss = cpy._ss;
	_lastSort = cpy._lastSort;
	return (*this);
}

Span::const_iterator	Span::begin(void) const
{
	return (const_iterator(_vector.begin()));
}

Span::const_iterator	Span::end(void) const
{
	return (const_iterator(_vector.end()));
}

void	Span::addNumber(const int &n)
{
	if (_vector.size() == _N)
		throw (SMRE);
	_vector.push_back(n);
}

char	Span::alreadySorted(void) const
{
	return (_vector.size() == _lastSort);
}

void	Span::sort(void)
{
	std::sort(_vector.begin(), _vector.end());
	_lastSort = _vector.size();
}

unsigned int	Span::shortestSpan(void)
{
	const unsigned int	size = (unsigned int)_vector.size();
	if (size <= 1)
		throw (NSE);
	if (_ss)
	{
		if (alreadySorted())
			return (_ss);
		sort();
		for (unsigned int i = 1; i < size; ++i)
		{
			if ((unsigned int)(_vector[i] - _vector[i - 1]) < _ss)
			{
				_ss = (unsigned int)(_vector[i] - _vector[i - 1]);
				if (!_ss)
					return (_ss);
			}
		}
	}
	return (_ss);
}

unsigned int	Span::longestSpan(void)
{
	if (_vector.size() <= 1)
		throw (NSE);
	if (!alreadySorted())
		sort();
	return ((unsigned int)(_vector[_vector.size() - 1] - _vector[0]));
}
