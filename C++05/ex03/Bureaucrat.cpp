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
#include "AForm.hpp"

const GradeTooHighException	Bureaucrat::GTHE;
const GradeTooLowException	Bureaucrat::GTLE;

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name)
{
	if (grade < 1)
		throw (GTHE);
	if (grade > 150)
		throw (GTLE);
	_grade = grade;
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name)
{
	*this = cpy;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat default destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &cpy)
{
	if (cpy._grade < 1)
		throw (GTHE);
	if (cpy._grade > 150)
		throw (GTLE);
	_grade = cpy._grade;
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	return (*this);
}

Bureaucrat	&Bureaucrat::operator++(void)
{
	if (_grade <= 1)
		throw (GTHE);
	--_grade;
	return (*this);
}

Bureaucrat	&Bureaucrat::operator--(void)
{
	if (_grade >= 150)
		throw (GTLE);
	++_grade;
	return (*this);
}

inline const unsigned char	&Bureaucrat::getGrade(void) const
{
	return (_grade);
}

inline const std::string	&Bureaucrat::getName(void) const
{
	return (_name);
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &lhs, const Bureaucrat &rhs)
{
	lhs << rhs.getName() << ", bureaucrat grade " << (int)rhs.getGrade() << '.' << std::endl;
	return (lhs);
}

const char	*GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low !");
}

const char	*GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High !");
}
