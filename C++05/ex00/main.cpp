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
}
