/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:31:27 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/16 14:31:27 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T> class	Array
{
	private: /* -Data- */
		T										*_arr;
		std::size_t								_size;
	private: /* -Exceptions- */
		class	OutOfBoundsException : public std::exception
		{
			const char	*what(void) const throw()
			{
				return ("OutOfBoundsException: Index out of bounds");
			}
		};
		class	EmptyArrayException : public std::exception
		{
			const char	*what(void) const throw()
			{
				return ("EmptyArrayException: Array already empty");
			}
		};
		class	SizeMaxReachedException : public std::exception
		{
			const char	*what(void) const throw()
			{
				return ("SizeMaxReachedException: Can't expand size");
			}
		};

	public: /* -CDstructors- */
		Array(void);
		Array(const std::size_t &n);
		Array(const Array &cpy);
		~Array(void);
	public: /* -Operators- */
		Array									&operator=(const Array &cpy);
		Array									operator+(const Array &add) const;
		Array									&operator+=(const Array &add);
		T										&operator[](const std::size_t &idx);
		const T									&operator[](const std::size_t &idx) const;
	public: /* -Getter- */
		const std::size_t						&size(void) const { return (_size); };
	public: /* -Methods- */
		void									pushBack(const T &obj);
		void									pushFront(const T &obj);
		void									remove(const std::size_t &idx);
		void									print(void) const;
	public: /* -Exceptions- */
		static const OutOfBoundsException		OOBE;
		static const EmptyArrayException		EAE;
		static const SizeMaxReachedException	SMRE;
};

template <typename T> std::ostream	&operator<<(std::ostream &lhs, const Array<T> &rhs);

#include "Array.tpp"
