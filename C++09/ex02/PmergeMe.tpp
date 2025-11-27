/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:50:36 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/11/27 15:50:36 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename C> void	PmergeMe<C>::print(void) const
{
	std::size_t	csize = size();
	for (std::size_t i = 0; i < csize; ++i)
	{
		std::cout << _ctn[i];
		if (i + 1 < csize)
			std::cout << ' ';
	}
	std::cout << std::endl;
}
