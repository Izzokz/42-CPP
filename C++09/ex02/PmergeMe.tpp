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

inline void	ft_swap(unsigned &c1, unsigned &c2)
{
	unsigned	tmp = c1;
	c1 = c2;
	c2 = tmp;
}

template <typename C> void	ft_moveToEnd(C &ctn, const std::size_t &end, std::size_t size)
{
	const std::size_t			pos = end - (++size - 2);
	while (--size)
	{
		ctn.push_back(ctn[pos]);
		ctn.erase(ctn.begin() + pos);
	}
}

template <typename C> void	ft_moveTo(C &ctn, const std::size_t &end, std::size_t size, std::size_t to)
{
	if (to > end - size)
		to -= size + 1;
	const std::size_t	pos = end - (++size - 2);
	while (--size)
	{
		ctn.insert(ctn.begin() + to, ctn[pos]);
		std::cout << (pos + (to <= pos ? 1 : 0)) << std::endl;
		ctn.erase(ctn.begin() + pos + (to <= pos ? 1 : 0));
		++to;
	}
}

#define JSIZE 50
static const std::size_t	g_jacobsthalNumbers[JSIZE] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123, 22906492245, 45812984491, 91625968981, 183251937963, 366503875925, 733007751851, 1466015503701, 2932031007403, 5864062014805, 11728124029611, 23456248059221, 46912496118443, 93824992236885, 187649984473771};

template <typename C> void	PmergeMe<C>::sort(void)
{
	std::size_t						step = 1;
	std::size_t						doublestep = 2;
	std::size_t						csize = size();
	std::size_t						halfcsize = csize / 2;
	while (step < halfcsize)
	{
		for (std::size_t i = doublestep - 1; i < csize; i += doublestep)
		{
			if (_ctn[i - step] > _ctn[i])
			{
				for (std::size_t x = 0; x < step; ++x)
					ft_swap(_ctn[i - step - x], _ctn[i - x]);
			}
		}
		step *= 2;
		doublestep *= 2;
	}
	step /= 2;
	while (step /= 2)
	{
		std::size_t					pendPos = size();
		std::size_t					getterPos = step + step - 1;
		// making pend
		while (getterPos + 1 < pendPos)
		{
			ft_moveToEnd(_ctn, getterPos += step, step);
			pendPos -= step;
		}
		print();
		std::size_t					iter = 2;
		std::size_t					fadd = 0;
		while (pendPos < csize)
		{
			std::size_t				field = *(g_jacobsthalNumbers + ++iter);
			{
				std::size_t			tmpNStep = (field - *(g_jacobsthalNumbers + iter - 1)) * step;
				if (pendPos + tmpNStep > csize)
					field = ((pendPos + tmpNStep - 1) - csize) / step;
			}
			std::size_t				n = field + fadd - *(g_jacobsthalNumbers + iter - 1) + 1;
			char					fsub = 0;
			while (--n)
			{
				const unsigned		val = _ctn[pendPos + step * n - 1];
				std::size_t			move = step * (field + fadd - fsub);
				while (move)
				{
					if (_ctn[move - 1] <= val)
						break ;
					move -= step;
				}
				ft_moveTo(_ctn, pendPos + (step * n) - 1, step, move);
				pendPos += step;
				if (move / step == field + fadd - fsub)
					fsub = 1;
				else
					fsub = 0;
				++fadd;
			}
		}
	}
}
