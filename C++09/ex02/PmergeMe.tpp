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

template <typename C> char	PmergeMe<C>::isSorted(void) const
{
	std::size_t	csize = size();
	for (std::size_t i = 1; i < csize; ++i)
	{
		if (_ctn[i] < _ctn[i - 1])
			return (0);
	}
	return (1);
}

inline void	ft_swap(unsigned &c1, unsigned &c2)
{
	unsigned	tmp = c1;
	c1 = c2;
	c2 = tmp;
}

template <typename C> void	ft_printDetailedCtn(C &ctn, const std::size_t &step, const std::size_t &pendPos)
{
	std::size_t	csize = ctn.size();
	char		switchColor = 0;
	std::size_t	endOfMain = pendPos - (pendPos % step) - 1;
	std::size_t	diff = 0;
	std::cout << "\033[45;1m";
	for (std::size_t i = 0; i < csize; ++i)
	{
		std::cout << ctn[i];
		if (i + 1 < csize)
			std::cout << ' ';
		if (i == endOfMain)
			std::cout << "\033[41;1m";
		if (i + 1 == pendPos)
			diff = endOfMain - pendPos + 1;
		if (!((i + 1) % step + diff))
		{
			if (i + 1 >= pendPos)
				std::cout << ((switchColor = !switchColor) ? "\033[44;1m" : "\033[43;1m");
			else if (i < endOfMain)
				std::cout << ((switchColor = !switchColor) ? "\033[46;1m" : "\033[45;1m");
		}
	}
	std::cout << "\033[0m" << std::endl;
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

template <typename C> void	ft_moveTo(C &ctn, std::size_t end, std::size_t size, std::size_t to)
{
	// No need to handle the case where <to> is larger than `end - (size - 1)` because it will never occur in this algorithm
	const std::size_t	newEnd = end + 1;
	++size;
	while (--size)
	{
		ctn.insert(ctn.begin() + to, ctn[end]);
		ctn.erase(ctn.begin() + newEnd);
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
//	std::cout << "\033[31;1m[INIT] PAIRING\033[0m" << std::endl;
//	print();
	while (step /= 2)
	{
		if (csize / step < 3)
			continue ;
		std::size_t					pendPos = csize;
		std::size_t					getterPos = step + step - 1;
		// making pend
		std::cout << "CREATING PEND:\n";
		while ((getterPos += step) + 1 <= pendPos)
		{
			ft_moveToEnd(_ctn, getterPos, step);
			pendPos -= step;
			std::cout << "GETTER_POS = " << getterPos << std::endl;
			ft_printDetailedCtn(_ctn, step, pendPos);
		}
		std::cout << "\033[31;1mPEND CREATED (STEP " << step << ") :\033[0m\n";
		ft_printDetailedCtn(_ctn, step, pendPos);
//		std::cout << "\033[31;1mSTART OF STEP [" << step << "]\033[0m" << std::endl;
//		std::cout << "\033[31;1mPEND CREATED :\033[0m" << std::endl;
//		print();
		std::size_t					iter = 2;
		while (pendPos < csize)
		{
			std::size_t				field = *(g_jacobsthalNumbers + ++iter);
			std::size_t				n = ((pendPos + ((field - *(g_jacobsthalNumbers + iter - 1)) * step) > csize) ? ((csize - pendPos) / step + 1) : field - *(g_jacobsthalNumbers + iter - 1) + 1);
			char					fsub = 0;
			std::size_t				fadd = 0;
			while (--n)
			{
				const unsigned		val = _ctn[pendPos + step * n - 1];
				std::size_t			initMove = step * (field + fadd - fsub);
				std::size_t			move;
//				std::cout << "INIT MOVE = " << initMove << ", PEND POS = " << pendPos << std::endl;
				if (initMove > pendPos)
					initMove -= step;
				move = initMove;
				while (move)
				{
					if (_ctn[move - 1] <= val)
						break ;
					move -= step;
				}
				std::cout << "MOVING ELEMENT No." << n << " FROM PEND TO MAIN AT " << move << std::endl;
//				std::cout << "N = " << n << ", FIELD = " << (field + fadd + fsub) << std::endl;
				ft_moveTo(_ctn, pendPos + (step * n) - 1, step, move);
//				std::cout << "ATFER MOVE:\n";
//				print();
				pendPos += step;
				if (initMove == move)
					fsub = 1;
				else
					fsub = 0;
				++fadd;
				ft_printDetailedCtn(_ctn, step, pendPos);
			}
		}
//		std::cout << "\033[31;1mEND OF STEP [" << step << "]\033[0m" << std::endl;
		std::cout << std::endl;
	}
}
