/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:44:31 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/18 15:44:31 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	Bureaucrat;

class	CannotEditFileException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

class	ShrubberyCreationForm : virtual public AForm
{
	private: /* -Data- */
		std::string								_target;
		static const CannotEditFileException	CEFE;

	public: /* -CDstructors- */
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
		~ShrubberyCreationForm(void);
	public: /* -Operator- */
		ShrubberyCreationForm					&operator=(const ShrubberyCreationForm &cpy);
	public: /* -Method- */
		void									execute(const Bureaucrat &exe) const;
};
