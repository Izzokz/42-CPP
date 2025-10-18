/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:56:16 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/18 19:56:43 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>

class	Span
{
	private: /* -Data- */
		std::vector<int>						_vector;
		unsigned int							_N;
		unsigned int							_ss;
		unsigned int							_lastSort;
	private: /* -Exceptions- */
		class	NoSpanException : public std::exception
		{
			const char	*what(void) const throw()
			{
				return ("NoSpanException: No span can be established (not enough data)");
			}
		};
		class	SizeMaxReachedException : public std::exception
		{
			const char	*what(void) const throw()
			{
				return ("SizeMaxReachedException: Capacity is full");
			}
		};

	public: /* -CDstructors- */
		Span(void);
		Span(const unsigned int &N);
		Span(const Span &cpy);
	public: /* -Operator- */
		Span									&operator=(const Span &cpy);
	public: /* -Methods- */
		void									addNumber(const int &n);
		void									sort(void);
		char									alreadySorted(void) const;
		unsigned int							shortestSpan(void);
		unsigned int							longestSpan(void);
	public: /* -Exceptions- */
		static const NoSpanException			NSE;
		static const SizeMaxReachedException	SMRE;
};
