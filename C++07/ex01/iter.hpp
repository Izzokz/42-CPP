/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:29:02 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/16 11:51:56 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T, typename F> void	iter(T *const arr, const std::size_t &size, F &f)
{
	for (std::size_t i = 0; i < size; ++i)
		f(*(arr + i));
}
