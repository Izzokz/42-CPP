/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 03:14:03 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/16 03:14:04 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const GradeTooHighException	Bureaucrat::GradeTooHighException;
const GradeTooLowException	Bureaucrat::GradeTooLowException;

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException);
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException);
	_grade = grade;
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name)
{
	if (cpy._grade < 1)
		throw (Bureaucrat::GradeTooHighException);
	if (cpy._grade > 150)
		throw (Bureaucrat::GradeTooLowException);
	_grade = cpy._grade;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &cpy)
{
	if (cpy._grade < 1)
		throw (Bureaucrat::GradeTooHighException);
	if (cpy._grade > 150)
		throw (Bureaucrat::GradeTooLowException);
	_grade = cpy._grade;
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat default destructor called" << std::endl;
}

inline unsigned char	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

inline const std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

std::ostream	&operator<<(std::ostream &lhs, const Bureaucrat &rhs)
{
	lhs << rhs.getName() << ", bureaucrat grade " << (int)rhs.getGrade() << '.' << std::endl;
	return (lhs);
}
