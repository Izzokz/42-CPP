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

class	Form;

class	GradeTooHighException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

class	GradeTooLowException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

class	Bureaucrat
{
	private: /* -Data- */
		const std::string					_name;
		unsigned char						_grade;

	public: /* -CDstructors- */
		Bureaucrat(const std::string &name, const int &grade);
		~Bureaucrat(void);
		Bureaucrat(const Bureaucrat &cpy);
	public: /* -Operators- */
		Bureaucrat							&operator=(const Bureaucrat &cpy);
		Bureaucrat							&operator++(void);
		Bureaucrat							&operator--(void);
	public: /* -Getters- */
		const unsigned char					&getGrade(void) const;
		const std::string					&getName(void) const;
	public: /* -Method- */
		void								signForm(Form &) const;
	public: /* -Exceptions- */
		static const GradeTooHighException	GTHE;
		static const GradeTooLowException	GTLE;
};

std::ostream	&operator<<(std::ostream &lhs, const Bureaucrat &rhs);
