/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:35:44 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/14 19:35:44 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

// Used for tests
typedef struct Data
{
	int			i;
	int			*iP;
	char		c;
	std::string	str;
	std::string	*strPtr;
}	Data;

class	Serializer
{
	private: /* -Pure Static Class- */
		Serializer(void) { };
		~Serializer(void) { };

	public: /* -Methods- */
		static uintptr_t	serialize(const Data *const &ptr);
		static Data			*deserialize(const uintptr_t &raw);
};
