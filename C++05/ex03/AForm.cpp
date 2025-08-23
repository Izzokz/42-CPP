/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:42:16 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/18 15:34:33 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const GradeTooHighException		AForm::GradeTooHighException;
const GradeTooLowException		AForm::GradeTooLowException;
const AlreadySignedException	AForm::AlreadySignedException;
const NotSignedException		AForm::NotSignedException;

AForm::AForm(const std::string &name, const int &signLevel, const int &execLevel) : _name(name), _signLevel(signLevel), _execLevel(execLevel)
{
	if (_signLevel < 1 || _execLevel < 1)
		throw (AForm::GradeTooHighException);
	if (_signLevel > 150 || _execLevel > 150)
		throw (AForm::GradeTooLowException);
	_signed = 0;
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &cpy) : _name(cpy._name), _signLevel(cpy._signLevel), _execLevel(cpy._execLevel)
{
	if (_signLevel < 1 || _execLevel < 1)
		throw (AForm::GradeTooHighException);
	if (_signLevel > 150 || _execLevel > 150)
		throw (AForm::GradeTooLowException);
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm	&AForm::operator=(const AForm &cpy)
{
	_signed = cpy._signed;
	std::cout << "AForm copy assignment operator called" << std::endl;
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

void	AForm::beSigned(const Bureaucrat &br)
{
	if (_signed)
		throw (this->AlreadySignedException);
	if (br.getGrade() > this->getSignLevel())
		throw (this->GradeTooLowException);
	_signed = 1;
}

inline unsigned char	AForm::isSigned(void) const
{
	return (_signed);
}

inline unsigned char	AForm::getSignLevel(void) const
{
	return (_signLevel);
}

inline unsigned char	AForm::getExecLevel(void) const
{
	return (_execLevel);
}

inline std::string	AForm::getName(void) const
{
	return (_name);
}

void	AForm::setSigned(const char &i)
{
	_signed = !!i;
}

std::ostream	&operator<<(std::ostream &lhs, const AForm &rhs)
{
	lhs << "AForm [" << rhs.getName() << "]: ";
	if (rhs.isSigned())
		lhs << "Signed (";
	else
		lhs << "Not signed (";
	lhs << (int)rhs.getSignLevel() << " to sign, " << (int)rhs.getExecLevel() << " to execute)";
	return (lhs);
}
