/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:11:10 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/16 11:11:10 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <typeinfo>
#include <cstdlib>

template <typename T> void	swap(T &a, T &b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T		min(const T &a, const T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T> T		max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	return (b);
}

template <typename T> void	puts(const T a, const T b)
{
	std::cout << "[" << typeid(T).name() << "]\na = " << a << "\nb = " << b << '\n' << std::endl;
}

class	TestClass
{
	private:
		const int	_seed;

	public:
		TestClass(void) : _seed(std::rand()) {};
		int			getSeed(void) const { return (_seed); };
		char		operator<(const TestClass &comp) const { return (this < &comp); };
		char		operator>(const TestClass &comp) const { return (this > &comp); };
};

inline std::ostream	&operator<<(std::ostream &lhs, const TestClass &rhs)
{
	lhs << rhs.getSeed();
	return (lhs);
}
