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
		const char	*what(void) const throw()
		{
			return ("Cannot Edit File !");
		}
};

class	ShrubberyCreationForm : virtual public AForm
{
	private:
		std::string								_target;
		static const CannotEditFileException	CannotEditFileException;
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
		ShrubberyCreationForm					&operator=(const ShrubberyCreationForm &cpy);
		~ShrubberyCreationForm(void);
		void									execute(const Bureaucrat &exe) const;
};
