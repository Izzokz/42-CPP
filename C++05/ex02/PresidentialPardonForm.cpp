/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:42:25 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/22 15:59:44 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
	std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy.getName(), cpy.getSignLevel(), cpy.getExecLevel())
{
	*this = cpy;
	std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
	setSigned(cpy.isSigned());
	_target = cpy._target;
	std::cout << "PresidentialPardonForm copy assignment operator called\n";
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called\n";
}

void	PresidentialPardonForm::execute(const Bureaucrat &exe) const
{
	if (!isSigned())
		throw (NSE);
	if (exe.getGrade() > getExecLevel())
		throw (GTLE);
	std::cout << "\e[38;2;212;176;34m" << _target << " has been pardoned by Zaphod Beeblebrox.\e[0m" << std::endl;
}
