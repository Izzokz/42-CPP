/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:54:42 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/12 16:54:44 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point(void);
		Point(const Fixed x, const Fixed y);
		Point(const Point &cpy);
		Point	&operator=(const Point &cpy);
		~Point(void);
		float	getX(void) const;
		float	getY(void) const;
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif
