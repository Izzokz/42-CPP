/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:34:32 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/05/13 17:34:34 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point p)
{
	Fixed	abc((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
	Fixed	bcp((b.getX() * (c.getY() - p.getY()) + c.getX() * (p.getY() - b.getY()) + p.getX() * (b.getY() - c.getY())) / 2);
	Fixed	abp((a.getX() * (b.getY() - p.getY()) + b.getX() * (p.getY() - a.getY()) + p.getX() * (a.getY() - b.getY())) / 2);
	Fixed	acp((a.getX() * (c.getY() - p.getY()) + c.getX() * (p.getY() - a.getY()) + p.getX() * (a.getY() - c.getY())) / 2);

	if (abc.toFloat() < 0)
		abc = Fixed(-abc.toFloat());
	if (bcp.toFloat() < 0)
		bcp = Fixed(-bcp.toFloat());
	if (abp.toFloat() < 0)
		abp = Fixed(-abp.toFloat());
	if (acp.toFloat() < 0)
		acp = Fixed(-acp.toFloat());
	return (bcp.toFloat() && abp.toFloat() && acp.toFloat() && abc == (bcp + abp + acp));
}
