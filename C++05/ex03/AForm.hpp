/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 07:15:39 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/18 15:34:45 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	GradeTooHighException;
class	GradeTooLowException;
class	Bureaucrat;

class	AlreadySignedException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

class	NotSignedException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

class	AForm
{
	private: /* -Data- */
		const std::string					_name;
		unsigned char						_signed : 1;
		const unsigned char					_signLevel;
		const unsigned char					_execLevel;

	protected:
		void								setSigned(const char &i);
		static const GradeTooLowException	GTLE;
		static const GradeTooHighException	GTHE;
		static const AlreadySignedException	ASE;
		static const NotSignedException		NSE;

	public: /* -CDstructors- */
		AForm(const std::string &name, const int &signLevel, const int &execLevel);
		AForm(const AForm &cpy);
		virtual ~AForm(void);
	public: /* -Operator- */
		AForm								&operator=(const AForm &cpy);
	public: /* -Methods- */
		virtual void						beSigned(const Bureaucrat &b);
		virtual void						execute(const Bureaucrat &exe) const = 0;
	public: /* -Getters- */
		virtual const unsigned char			&getExecLevel(void) const;
		virtual const unsigned char			&getSignLevel(void) const;
		virtual const std::string			&getName(void) const;
		virtual unsigned char				isSigned(void) const;
};

std::ostream	&operator<<(std::ostream &lhs, const AForm &rhs);
