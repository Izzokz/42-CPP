/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:20:40 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/22 16:20:40 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	UnknownFormException : public std::exception
{
	public:
		const char	*what(void) const throw()
		{
			return ("Unknown Form Exception !");
		}
};

class	Intern
{
	private:
		static const UnknownFormException	UnknownFormException;
	public:
		Intern(void);
		Intern(const Intern &cpy);
		Intern								&operator=(const Intern &cpy);
		~Intern(void);
		AForm								*makeForm(const std::string &type, const std::string &target) const;
};
