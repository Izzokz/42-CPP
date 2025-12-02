/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:50:31 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/11/27 15:50:31 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename C> class	PmergeMe
{
	private: /* -Data- */
		C			_ctn;
		C			_pend;

	public: /* -Constructors- */
		PmergeMe(void) { };
		PmergeMe(const PmergeMe &cpy) : _ctn(cpy._ctn) { };
	public: /* -Operators- */
		PmergeMe	&operator=(const PmergeMe &cpy) { _ctn = cpy._ctn; return (*this); };
	public: /* -Methods- */
		void		add(const unsigned int &i) { _ctn.push_back(i); };
		std::size_t	size(void) const { return (_ctn.size()); };
		void		sort(void);
		void		print(void) const;
};

#include "PmergeMe.tpp"
