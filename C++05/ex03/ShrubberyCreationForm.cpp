/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:58:12 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/18 15:58:12 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

const CannotEditFileException	ShrubberyCreationForm::CannotEditFileException;

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy.getName(), cpy.getSignLevel(), cpy.getExecLevel())
{
	_target = cpy._target;
	setSigned(cpy.isSigned());
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	setSigned(cpy.isSigned());
	_target = cpy._target;
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

static char	open_and_draw(const char *const target)
{
	std::ofstream			output(target, std::ios::trunc);
	const char *const		trees = "\n               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";

	if (!output.is_open())
		return (0);
	output << trees;
	output.close();
	return (1);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &exe) const
{
	if (!isSigned())
		throw (this->NotSignedException);
	if (exe.getGrade() > getExecLevel())
		throw (this->GradeTooLowException);
	if (!open_and_draw((_target + "_shrubbery").c_str()))
		throw (this->CannotEditFileException);
}
