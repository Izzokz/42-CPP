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

const GradeTooHighException		AForm::GTHE;
const GradeTooLowException		AForm::GTLE;
const AlreadySignedException	AForm::ASE;
const NotSignedException		AForm::NSE;

AForm::AForm(const std::string &name, const int &signLevel, const int &execLevel) : _name(name), _signLevel(signLevel), _execLevel(execLevel)
{
	if (_signLevel < 1 || _execLevel < 1)
		throw (GTHE);
	if (_signLevel > 150 || _execLevel > 150)
		throw (GTLE);
	_signed = 0;
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &cpy) : _name(cpy._name), _signLevel(cpy._signLevel), _execLevel(cpy._execLevel)
{
	if (_signLevel < 1 || _execLevel < 1)
		throw (GTHE);
	if (_signLevel > 150 || _execLevel > 150)
		throw (GTLE);
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
		throw (ASE);
	if (br.getGrade() > _signLevel)
		throw (GTLE);
	_signed = 1;
}

inline unsigned char	AForm::isSigned(void) const
{
	return (_signed);
}

inline const unsigned char	&AForm::getSignLevel(void) const
{
	return (_signLevel);
}

inline const unsigned char	&AForm::getExecLevel(void) const
{
	return (_execLevel);
}

inline const std::string	&AForm::getName(void) const
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

const char	*AlreadySignedException::what(void) const throw()
{
	return ("Already Signed !");
}

const char	*NotSignedException::what(void) const throw()
{
	return ("Not Signed !");
}
