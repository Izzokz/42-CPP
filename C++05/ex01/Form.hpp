/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 07:15:39 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/16 08:09:14 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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

class	Form
{
	private:
		const std::string	_name;
		unsigned char		_signed : 1;
		const unsigned char	_signLevel;
		const unsigned char	_execLevel; // UNUSED
	public:
		Form(const std::string &name, const int &signLevel, const int &execLevel);
		Form(const Form &cpy);
		Form								&operator=(const Form &cpy);
		~Form(void);
		void								beSigned(const Bureaucrat &b);
		unsigned char						getExecLevel(void) const;
		unsigned char						getSignLevel(void) const;
		std::string							getName(void) const;
		unsigned char						isSigned(void) const;
		static const GradeTooLowException	GradeTooLowException;
		static const GradeTooHighException	GradeTooHighException;
		static const AlreadySignedException	AlreadySignedException;
};

std::ostream	&operator<<(std::ostream &lhs, const Form &rhs);
