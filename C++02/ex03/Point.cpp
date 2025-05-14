/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 17:14:41 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/12 17:14:42 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	std::cout << "\e[32;1mPoint default constructor called\e[0m\n";
}

Point::~Point(void)
{
	std::cout << "\e[31;1mPoint destructor called\e[0m\n";
}

Point::Point(const Point &cpy) : _x(cpy._x), _y(cpy._y)
{
	std::cout << "\e[32;1mPoint copy constructor called\e[m\n";
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{
	std::cout << "\e[32;1mPoint Fixed constructor called\e[0m\n";
}

Point	&Point::operator=(const Point &cpy)
{
	(void) cpy;
	std::cout << "\e[32;1mPoint copy assignment operator called\e[0m\n";
	return (*this);
}

float	Point::getX(void) const
{
	return (this->_x.toFloat());
}

float	Point::getY(void) const
{
	return (this->_y.toFloat());
}
