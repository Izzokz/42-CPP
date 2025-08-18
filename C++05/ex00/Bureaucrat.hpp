/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 02:52:41 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/16 02:52:43 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <typeinfo>

class	GradeTooHighException : public std::exception
{
	public:
		const char	*what(void) const throw()
		{
			return ("Grade Too High !");
		}
};

class	GradeTooLowException : public std::exception
{
	public:
		const char	*what(void) const throw()
		{
			return ("Grade Too Low !");
		}
};

class	Bureaucrat
{
	private:
		const std::string	_name;
		unsigned char		_grade;
	public:
		Bureaucrat(const std::string &name, const int &grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat			&operator=(const Bureaucrat &cpy);
		unsigned char		getGrade(void) const;
		const std::string	getName(void) const;
		static const GradeTooHighException	GradeTooHighException;
		static const GradeTooLowException	GradeTooLowException;
};

std::ostream	&operator<<(std::ostream &lhs, const Bureaucrat &rhs);
