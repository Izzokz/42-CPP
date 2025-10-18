/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:26:38 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/18 16:26:38 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>
#include <iostream>

template <typename T> int	easyfind(const T &container, const int &i)
{
	return (std::find(container.begin(), container.end(), i) != container.end() ? i : throw (std::out_of_range("Value not found")));
}

template <typename T> void	printContainer(const T &container)
{
	const std::size_t	&csize = container.size();
	std::cout << &container;
	for (std::size_t i = 0; i < csize; ++i)
		std::cout << '\n' << container[i];
	std::cout << '\n' << std::endl;
}
