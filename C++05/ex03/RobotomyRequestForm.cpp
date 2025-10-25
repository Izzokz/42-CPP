/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 14:50:53 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/22 14:50:53 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
	std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy.getName(), cpy.getSignLevel(), cpy.getExecLevel())
{
	*this = cpy;
	std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	setSigned(cpy.isSigned());
	_target = cpy._target;
	std::cout << "RobotomyRequestForm copy assignment operator called\n";
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called\n";
}

void	RobotomyRequestForm::execute(const Bureaucrat &exe) const
{
	static char	fiftyPercent = 0;

	if (!isSigned())
		throw (NSE);
	if (exe.getGrade() > getExecLevel())
		throw (GTLE);
	std::cout << "*Beep Bop Beep Bop Bop*\n*Pam Pam Pam*" << std::endl;
	if (!fiftyPercent)
		std::cout << "\e[31mRobotomy failed on " << _target << ".\e[0m" << std::endl;
	else
		std::cout << "\e[32m" << _target << " has been robotomized successfully.\e[0m" << std::endl;
	fiftyPercent = !fiftyPercent;
}
