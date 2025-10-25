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
		const char	*what(void) const throw();
};

class	Form
{
	private: /* -Data- */
		const std::string	_name;
		unsigned char		_signed : 1;
		const unsigned char	_signLevel;
		const unsigned char	_execLevel; // UNUSED IN THIS EXERCISE

	public: /* -CDstructors- */
		Form(const std::string &name, const int &signLevel, const int &execLevel);
		Form(const Form &cpy);
		~Form(void);
	public: /* -Operator- */
		Form								&operator=(const Form &cpy);
	public: /* -Method- */
		void								beSigned(const Bureaucrat &b);
	public: /* -Getters- */
		const unsigned char					&getExecLevel(void) const;
		const unsigned char					&getSignLevel(void) const;
		const std::string					&getName(void) const;
		unsigned char						isSigned(void) const;
	public: /* -Exceptions- */
		static const GradeTooLowException	GTLE;
		static const GradeTooHighException	GTHE;
		static const AlreadySignedException	ASE;
};

std::ostream	&operator<<(std::ostream &lhs, const Form &rhs);
