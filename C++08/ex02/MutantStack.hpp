/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <kzhen-cl@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:52:00 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/19 17:52:02 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T, typename C = std::deque<T> > class	MutantStack : public std::stack<T, C>
{
	public: /* -Inheritance- */
		typedef typename C::iterator		iterator;
		typedef typename C::const_iterator	const_iterator;
	public: /* -Methods- */
		iterator							begin(void) { return (this->c.begin()); };
		iterator							end(void) { return (this->c.end()); };
		const_iterator						begin(void) const { return (this->c.begin()); };
		const_iterator						end(void) const { return (this->c.end()); };
};
