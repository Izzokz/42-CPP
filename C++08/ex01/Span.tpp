/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:57:05 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/18 21:57:05 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

template <typename IT> void	Span::assign(IT begin, IT end)
{
	while (begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}
