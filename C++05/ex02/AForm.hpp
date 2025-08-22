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
		const char	*what(void) const throw()
		{
			return ("Already Signed !");
		}
};

class	NotSignedException : public std::exception
{
	public:
		const char	*what(void) const throw()
		{
			return ("Not Signed !");
		}
};

class	AForm
{
	private:
		const std::string	_name;
		unsigned char		_signed : 1;
		const unsigned char	_signLevel;
		const unsigned char	_execLevel;
	protected:
		void				setSigned(const char &i);
		static const GradeTooLowException	GradeTooLowException;
		static const GradeTooHighException	GradeTooHighException;
		static const AlreadySignedException	AlreadySignedException;
		static const NotSignedException		NotSignedException;
	public:
		AForm(const std::string &name, const int &signLevel, const int &execLevel);
		AForm(const AForm &cpy);
		AForm								&operator=(const AForm &cpy);
		~AForm(void);
		virtual void						beSigned(const Bureaucrat &b);
		virtual void						execute(const Bureaucrat &exe) const = 0;
		virtual unsigned char				getExecLevel(void) const;
		virtual unsigned char				getSignLevel(void) const;
		virtual std::string					getName(void) const;
		virtual unsigned char				isSigned(void) const;
};

std::ostream	&operator<<(std::ostream &lhs, const AForm &rhs);
