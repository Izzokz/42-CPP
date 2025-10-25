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
#include <iterator>

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
			const char	*what(void) const throw();
		};
		class	SizeMaxReachedException : public std::exception
		{
			const char	*what(void) const throw();
		};

	public: /* -CDstructors- */
		Span(void);
		Span(const unsigned int &N);
		Span(const Span &cpy);
	public: /* -Operator- */
		Span									&operator=(const Span &cpy);
	public: /* -Const Iterator- */
		class	const_iterator
		{
			private: /* -Data- */
				std::vector<int>::const_iterator		_it;

			public: /* -Constructor- */
				const_iterator(std::vector<int>::const_iterator it) : _it(it) { }
			public: /* -Iterator type- */
				typedef std::ptrdiff_t					difference_type;
				typedef const int						value_type;
				typedef const int						*pointer;
				typedef const int						&reference;
				typedef std::random_access_iterator_tag	iterator_category;
			public: /* -Operators- */
				const int								&operator*(void) const;
				char									operator==(const const_iterator &comp) const;
				char									operator!=(const const_iterator &comp) const;
				const_iterator							&operator++(void);
				const_iterator							operator++(int);
				const_iterator							&operator--(void);
				const_iterator							operator--(int);
				const_iterator							operator+(const difference_type &i) const;
				const_iterator							operator-(const difference_type &i) const;
				difference_type							operator-(const const_iterator &it) const;
				const_iterator							&operator+=(const difference_type &i);
				const_iterator							&operator-=(const difference_type &i);
				const int								&operator[](const std::size_t &i) const;
		};
	public: /* -Methods- */
		const_iterator							begin(void) const;
		const_iterator							end(void) const;
		void									addNumber(const int &n);
		template <typename IT> void				assign(IT begin, IT end);
		void									sort(void);
		char									alreadySorted(void) const;
		unsigned int							shortestSpan(void);
		unsigned int							longestSpan(void);
	public: /* -Exceptions- */
		static const NoSpanException			NSE;
		static const SizeMaxReachedException	SMRE;
};

#include "Span.tpp"
