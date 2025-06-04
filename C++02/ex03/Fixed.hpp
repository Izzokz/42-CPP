/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:11:01 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/12 11:11:03 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int			_raw;
		static const int	_bits = 24;
	public:
		Fixed(void);
		Fixed(const int raw);
		Fixed(const float f);
		Fixed(const Fixed &cpy);
		~Fixed(void);
		Fixed		&operator=(const Fixed &cpy);
		bool		operator==(const Fixed &f) const;
		bool		operator!=(const Fixed &f) const;
		bool		operator>(const Fixed &f) const;
		bool		operator<(const Fixed &f) const;
		bool		operator>=(const Fixed &f) const;
		bool		operator<=(const Fixed &f) const;
		Fixed		operator+(const Fixed &f) const;
		Fixed		operator-(const Fixed &f) const;
		Fixed		operator/(const Fixed &f) const;
		Fixed		operator*(const Fixed &f) const;
		Fixed		&operator++(void);
		Fixed		operator++(int);
		Fixed		&operator--(void);
		Fixed		operator--(int);
		int			toInt(void) const;
		float		toFloat(void) const;
		int			getRawBits(void) const;
		void		setRawBits(const int raw);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static Fixed		&min(Fixed &f1, Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
};

std::ostream	&operator<<(std::ostream &o, const Fixed &obj);

#endif
