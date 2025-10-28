/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:32:14 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/28 19:32:14 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static __attribute__((__always_inline__)) long long	ft_uniset(void)
{
	char	a;

	return ((long long)&a ^ 0xFF54252F5C2);
}

signed	ft_rand(void)
{
	static long long	lcg[2] = {ft_uniset() * 69, ft_uniset() % 69 + 12};

	return (((int)(long long)lcg * (*lcg ^= (*(lcg + 1) * 0x5DEECE66D))
		+ (*(lcg + 1) ^= (*lcg * 0x479E22 + (long long)ft_rand))) % 0x7FFFFFFF);
}
