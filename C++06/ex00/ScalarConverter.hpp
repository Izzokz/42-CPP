/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:49:51 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/14 17:49:51 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	ScalarConverter
{
	private: /* -Uninstantiable Class Hack- */
		ScalarConverter(void) {};
		~ScalarConverter(void) {};

	public:
		static void	convert(const std::string &);
};
