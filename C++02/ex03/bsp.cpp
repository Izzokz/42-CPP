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

static Fixed	fabs(const Fixed &f)
{
	if (f < Fixed(0))
		return (Fixed(-f.toFloat()));
	return (f);
}

bool	bsp(const Point a, const Point b, const Point c, const Point p)
{
	Fixed	abc((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
	Fixed	bcp((b.getX() * (c.getY() - p.getY()) + c.getX() * (p.getY() - b.getY()) + p.getX() * (b.getY() - c.getY())) / 2);
	Fixed	abp((a.getX() * (b.getY() - p.getY()) + b.getX() * (p.getY() - a.getY()) + p.getX() * (a.getY() - b.getY())) / 2);
	Fixed	acp((a.getX() * (c.getY() - p.getY()) + c.getX() * (p.getY() - a.getY()) + p.getX() * (a.getY() - c.getY())) / 2);

	abc = fabs(abc);
	bcp = fabs(bcp);
	abp = fabs(abp);
	acp = fabs(acp);
	return (bcp > Fixed(0) && abp > Fixed(0) && acp > Fixed(0) && fabs(abc - (bcp + abp + acp)) < Fixed(0.0001f));
}
