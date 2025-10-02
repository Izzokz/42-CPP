/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 02:52:47 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/08/16 02:52:48 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

typedef struct s_brct
{
	std::string	name;
	int			grade;
}	t_brct;

int	main(void)
{
	std::cout << "\n\e[33;1m---| TEST 1 |---\e[0m" << std::endl;
	{
		try
		{
			const Bureaucrat	br[2] = {Bureaucrat("A", 1), Bureaucrat("B", 151)};
			const t_brct		a = {"brct", 3};

			std::cout << *(Bureaucrat *)&a << std::endl;
			std::cout << *br << std::endl;
			std::cout << *(br + 1) << std::endl;
		}
		catch (std::exception &e)
		{
			if (typeid(e) == typeid(Bureaucrat::GradeTooHighException)
				|| typeid(e) == typeid(Bureaucrat::GradeTooLowException))
				std::cout << e.what() << std::endl;
			else
				std::cout << "Unkown exception occured" << std::endl;
		}
	}
	std::cout << "\n\e[33;1m---| TEST 2 |---\e[0m" << std::endl;
	{
		try
		{
			const Bureaucrat	br[2] = {Bureaucrat("A", 1), Bureaucrat("B", -151)};
			const t_brct		a = {"brct", 3};

			std::cout << *(Bureaucrat *)&a << std::endl;
			std::cout << *br << std::endl;
			std::cout << *(br + 1) << std::endl;
		}
		catch (std::exception &e)
		{
			if (typeid(e) == typeid(Bureaucrat::GradeTooHighException)
				|| typeid(e) == typeid(Bureaucrat::GradeTooLowException))
				std::cout << e.what() << std::endl;
			else
				std::cout << "Unkown exception occured" << std::endl;
		}
	}
	std::cout << "\n\e[33;1m---| TEST 3 |---\e[0m" << std::endl;
	{
		try
		{
			const Bureaucrat	br[2] = {Bureaucrat("A", 1), Bureaucrat("B", 15)};
			const t_brct		a = {"brct", 3};

			std::cout << *(Bureaucrat *)&a << std::endl;
			std::cout << *br << std::endl;
			std::cout << *(br + 1) << std::endl;
		}
		catch (std::exception &e)
		{
			if (typeid(e) == typeid(Bureaucrat::GradeTooHighException)
				|| typeid(e) == typeid(Bureaucrat::GradeTooLowException))
				std::cout << e.what() << std::endl;
			else
				std::cout << "Unkown exception occured" << std::endl;
		}
	}
	std::cout << "\n\e[33;1m---| TEST 4 |---\e[0m" << std::endl;
	{
		try
		{
			const Bureaucrat	br[2] = {Bureaucrat("A", 1), Bureaucrat("B", 15)};
			const t_brct		a = {"brct", -1}; // As this is NOT initialized (as a Bureaucrat), this is OK :D

			std::cout << *(Bureaucrat *)&a << std::endl;
			std::cout << *br << std::endl;
			std::cout << *(br + 1) << std::endl;
		}
		catch (std::exception &e)
		{
			if (typeid(e) == typeid(Bureaucrat::GradeTooHighException)
				|| typeid(e) == typeid(Bureaucrat::GradeTooLowException))
				std::cout << e.what() << std::endl;
			else
				std::cout << "Unkown exception occured" << std::endl;
		}
	}
	std::cout << "\n\e[33;1m---| TEST 5 |---\e[0m" << std::endl;
	{
		try
		{
			const Bureaucrat	b = Bureaucrat("ababa", 5);
			const Bureaucrat	c = b;
			Bureaucrat			c1 = Bureaucrat("afafa", 3);
			Bureaucrat			d = Bureaucrat(c);
			const t_brct		a = {"brct", -1};

			std::cout << b << std::endl;
			std::cout << c << std::endl;
			std::cout << d << std::endl;
			d = c1;
			std::cout << d << std::endl;
			d = *(Bureaucrat *)&a;
			std::cout << d << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n\e[33;1m---| TEST 6 |---\e[0m" << std::endl;
	{
		try
		{
			const t_brct			cheater = {"Jeannot", 0};
			ShrubberyCreationForm	a = ShrubberyCreationForm("TARGET");

			(*(Bureaucrat *)&cheater).signForm(a);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n\e[33;1m---| TEST 7 |---\e[0m" << std::endl;
	{
		try
		{
			const t_brct			cheater = {"Jeannot", 0};
			const t_brct			badcheater = {"NotJeannot", 255};
			Bureaucrat				notcheater = Bureaucrat("Jeannette", 16);
			ShrubberyCreationForm	a = ShrubberyCreationForm("T1");
			ShrubberyCreationForm	d("T2");

			(*(Bureaucrat *)&cheater).signForm(a);
			(*(Bureaucrat *)&badcheater).signForm(a);
			notcheater.executeForm(d);
			std::cout << d << std::endl;
			notcheater.signForm(d);
			std::cout << d << std::endl;
			(*(Bureaucrat *)&badcheater).executeForm(d);
			notcheater.executeForm(d);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n\e[33;1m---| TEST 8 |---\e[0m" << std::endl;
	{
		try
		{
			std::cout << "\e[33;1m-INIT-\e[0m" << std::endl;
			t_brct				a = {"Olivier", 73};
			t_brct				b = {"Olive", 46};
			RobotomyRequestForm	A("Saaraah");
			RobotomyRequestForm	B = A;
			std::cout << "\e[33;1m-INIT'D-\e[0m" << std::endl;

			std::cout << "\n\e[33;1m-Form A-\e[0m" << std::endl;
			(*(Bureaucrat *)&a).signForm(A);
			--(a.grade);
			(*(Bureaucrat *)&a).signForm(A);
			(*(Bureaucrat *)&a).executeForm(A);
			(*(Bureaucrat *)&b).executeForm(A);
			--(b.grade);
			(*(Bureaucrat *)&b).executeForm(A);
			a.grade = 3;
			(*(Bureaucrat *)&a).signForm(A);
			std::cout << "\e[33;1m-Form A End-\e[0m" << std::endl;
			std::cout << "\n\e[33;1m-Form B-\e[0m" << std::endl;
			std::cout << "B: " << B << std::endl;
			(*(Bureaucrat *)&a).signForm(B);
			std::cout << "B: " << B << std::endl;
			(*(Bureaucrat *)&a).executeForm(B);
			RobotomyRequestForm C("Haaraas");
			B = C;
			std::cout << "B: " << B << std::endl;
			(*(Bureaucrat *)&a).executeForm(B);
			(*(Bureaucrat *)&a).signForm(B);
			(*(Bureaucrat *)&a).executeForm(B);
			(*(Bureaucrat *)&a).signForm(B);
			std::cout << "\e[33;1m-Form B End-\e[0m" << std::endl;
			std::cout << "\n\e[33;1m-Loop B-\e[0m" << std::endl;
			for (char u = -1; u < 10; ++u)
				(*(Bureaucrat *)&a).executeForm(B);
			std::cout << "\e[33;1m-Loop B End-\e[0m" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n\e[33;1m---| TEST 9 |---\e[0m" << std::endl;
	{
		try
		{
			t_brct	a = {"Jeanne", 0};
			PresidentialPardonForm	A((*(Bureaucrat *)&a).getName());

			(*(Bureaucrat *)&a).signForm(A);
			(*(Bureaucrat *)&a).executeForm(A);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n\e[33;1m---| TEST 10 |---\e[0m" << std::endl;
	{
		try
		{
			AForm		*forms[9];
			t_brct		a = {"Oui", 0};
			char		names[3][4] = {{'s', 'c', '\0', '\0'}, {'r', 'r', '\0', '\0'}, {'p', 'p', '\0', '\0'}};

			for (char i = 0; i < 3; ++i)
			{
				*(*names + 2) = i + '0';
				*(forms + i * 3) = (*(Intern *)69).makeForm("shrubbery creation", *names);
			}
			for (char i = 0; i < 3; ++i)
			{
				*(*(names + 1) + 2) = i + '0';
				*(forms + i * 3 + 1) = (*(Intern *)0).makeForm("robotomy request", *(names + 1));
			}
			for (char i = 0; i < 3; ++i)
			{
				*(*(names + 2) + 2) = i + '0';
				*(forms + i * 3 + 2) = (*(Intern *)30035).makeForm("presidential pardon", *(names + 2));
			}
			for (char i = 0; i < 9; ++i)
			{
				std::cout << **(forms + i) << std::endl;
				(*(Bureaucrat *)&a).signForm(**(forms + i));
				(*(Bureaucrat *)&a).executeForm(**(forms + i));
				delete (*(forms + i));
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
