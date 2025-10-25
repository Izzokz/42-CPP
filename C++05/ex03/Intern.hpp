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
		const char	*what(void) const throw();
};

class	Intern
{
	private: /* -Exception- */
		static const UnknownFormException	UFE;

	public: /* -CDstructors- */
		Intern(void);
		Intern(const Intern &cpy);
		~Intern(void);
	public: /* -Operator- */
		Intern								&operator=(const Intern &cpy);
	public: /* -Method- */
		AForm								*makeForm(const std::string &type, const std::string &target) const;
};
