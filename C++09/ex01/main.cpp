/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:40:01 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/11/10 18:40:01 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>

__attribute__((__always_inline__))
static long	popTop(std::stack<long> &stk)
{
	long	val = stk.top();
	stk.pop();
	return (val);
}

__attribute__((__always_inline__))
static char	calcFromStack(std::stack<long> &stk, const char &c)
{
	if (c != '+' && c != '-' && c != '*' && c != '/')
	{
		std::cout << "Error: Unkown character" << std::endl;
		return (0);
	}
	else if (stk.size() < 2)
	{
		std::cout << "Error: Not enough values to calculate" << std::endl;
		return (0);
	}

	if (c == '+')
	{
		stk.push(popTop(stk) + popTop(stk));
		return (1);
	}
	if (c == '-')
	{
		long	rhs = popTop(stk);
		stk.push(popTop(stk) - rhs);
		return (1);
	}
	if (c == '*')
	{
		stk.push(popTop(stk) * popTop(stk));
		return (1);
	}
	long		rhs = popTop(stk);
	if (!rhs)
	{
		std::cout << "Error: Can't divide by zero" << std::endl;
		return (0);
	}
	stk.push(popTop(stk) / rhs);
	return (1);
}

__attribute__((__always_inline__))
static void	ft_RPNCalculate(const char *&rpn)
{
	std::stack<long>	stk;
	char				spaceBefore = 1;
	--rpn;
	while (*++rpn)
	{
		char			current = *rpn;
		if (std::isspace(current))
			spaceBefore = 1;
		else if (current >= '0' && current <= '9')
		{
			if (!spaceBefore)
			{
				std::cout << "Error: Space between each character needed" << std::endl;
				return ;
			}
			stk.push(current - '0');
			spaceBefore = 0;
		}
		else
		{
			if (!spaceBefore)
			{
				std::cout << "Error: Space between each character needed" << std::endl;
				return ;
			}
			if (!calcFromStack(stk, current))
				return ;
		}
	}
	const std::size_t	ssize = stk.size();
	if (!ssize)
		std::cout << "Error: Nothing to do" << std::endl;
	else if (ssize != 1)
		std::cout << "Error: Misses calculations" << std::endl;
	else
		std::cout << stk.top() << std::endl;
}

int	main(int argc, const char *argv[])
{
	while (--argc)
		ft_RPNCalculate(*++argv);
}
