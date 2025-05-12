/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:11:26 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/12 12:11:27 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	this->_raw = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int raw)
{
	this->_raw = raw << this->_bits;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float f)
{
	this->_raw = roundf(f * (1 << this->_bits));
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed &cpy)
{
	std::cout << "Copy constructor called\n";
	*this = cpy;
}

Fixed	&Fixed::operator=(const Fixed &cpy)
{
	std::cout << "Copy assignment operator called\n";
	this->_raw = cpy.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (float)(1 << this->_bits));
}

int	Fixed::getRawBits(void) const
{
	return (this->_raw);
}

void	Fixed::setRawBits(const int raw)
{
	this->_raw = raw;
}

std::ostream	&operator<<(std::ostream &o, const Fixed &obj)
{
	o << obj.toFloat();
	return (o);
}
