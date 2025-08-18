/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:42:16 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/18 09:42:16 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

const GradeTooHighException		Form::GradeTooHighException;
const GradeTooLowException		Form::GradeTooLowException;
const AlreadySignedException	Form::AlreadySignedException;

Form::Form(const std::string &name, const int &signLevel, const int &execLevel) : _name(name), _signLevel(signLevel), _execLevel(execLevel)
{
	if (_signLevel < 1 || _execLevel < 1)
		throw (Form::GradeTooHighException);
	if (_signLevel > 150 || _execLevel > 150)
		throw (Form::GradeTooLowException);
	_signed = 0;
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &cpy) : _name(cpy._name), _signLevel(cpy._signLevel), _execLevel(cpy._execLevel)
{
	if (_signLevel < 1 || _execLevel < 1)
		throw (Form::GradeTooHighException);
	if (_signLevel > 150 || _execLevel > 150)
		throw (Form::GradeTooLowException);
	std::cout << "Form copy constructor called" << std::endl;
}

Form	&Form::operator=(const Form &cpy)
{
	_signed = cpy._signed;
	std::cout << "Form copy assignment operator called" << std::endl;
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

void	Form::beSigned(const Bureaucrat &br)
{
	if (_signed)
		throw (this->AlreadySignedException);
	if (br.getGrade() > this->getSignLevel())
		throw (this->GradeTooLowException);
	_signed = 1;
}

inline unsigned char	Form::isSigned(void) const
{
	return (_signed);
}

inline unsigned char	Form::getSignLevel(void) const
{
	return (_signLevel);
}

inline unsigned char	Form::getExecLevel(void) const
{
	return (_execLevel);
}

inline std::string	Form::getName(void) const
{
	return (_name);
}

std::ostream	&operator<<(std::ostream &lhs, const Form &rhs)
{
	lhs << "Form [" << rhs.getName() << "]: ";
	if (rhs.isSigned())
		lhs << "Signed (";
	else
		lhs << "Not signed (";
	lhs << (int)rhs.getSignLevel() << " to sign, " << (int)rhs.getExecLevel() << " to execute)";
	return (lhs);
}
