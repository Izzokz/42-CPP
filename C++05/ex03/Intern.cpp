/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:20:35 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/22 16:20:35 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const UnknownFormException	Intern::UnknownFormException;

Intern::Intern(void)
{
	std::cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern &cpy)
{
	(void) cpy;
	std::cout << "Intern copy constructor called\n";
}

Intern	&Intern::operator=(const Intern &cpy)
{
	(void) cpy;
	std::cout << "Intern copy assignment operator called\n";
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called\n";
}

static inline AForm	*createSC(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static inline AForm	*createRR(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static inline AForm	*createPP(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target) const
{
	AForm						*newForm = NULL;
	static const char *const	list[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	static AForm				*(*formTypes[3])(const std::string &) = {createSC, createRR, createPP};

	try
	{
		for (char type = 0; type < 3; ++type)
		{
			if (name == *(list + type))
			{
				newForm = ((*(formTypes + type))(target));
				std::cout << "Intern creates " << newForm->getName() << std::endl;
				return (newForm);
			}
		}
		throw (this->UnknownFormException);
	}
	catch (std::exception &e)
	{
		std::cout << "Intern couldn't create " << target << " because " << e.what() << std::endl;
	}
	return (NULL);
}
