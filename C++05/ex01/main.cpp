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
#include "Form.hpp"

typedef struct s_brct
{
	std::string	name;
	int			grade;
}	t_brct;

typedef struct s_form
{
	std::string		name;
	unsigned char	s : 1;
	unsigned char	sl;
	unsigned char	el;
}	t_form;

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
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
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
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
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
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
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
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
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
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n\e[33;1m---| TEST 6 |---\e[0m" << std::endl;
	{
		Bureaucrat	a("1", 1);
		Bureaucrat	b("150", 150);
		std::cout << a << std::endl << b << std::endl;
		try
		{
			++a;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			--b;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			while (1)
				--a;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << '\n' << a << std::endl;
		}
		try
		{
			while (1)
				++b;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << '\n' << b << std::endl;
		}
	}
	std::cout << "\n\e[33;1m---| TEST 7 |---\e[0m" << std::endl;
	{
		try
		{
			const t_brct	cheater = {"Jeannot", 0};
			Form			a = Form("A'", 200, 5);

			(*(Bureaucrat *)&cheater).signForm(a);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n\e[33;1m---| TEST 8 |---\e[0m" << std::endl;
	{
		try
		{
			const t_brct	cheater = {"Jeannot", 0};
			const t_brct	badcheater = {"NotJeannot", 255};
			Bureaucrat		notcheater = Bureaucrat("Jeannette", 16);
			Form			a = Form("A'", 16, 5);
			t_form			b = {"B'", 0, 150, 150};
			t_form			wasItEvenSigned = {"C'", 1, 16, 5};
			Form			d("D'", 16, 5);

			(*(Bureaucrat *)&cheater).signForm(a);
			(*(Bureaucrat *)&badcheater).signForm(a);
			(*(Bureaucrat *)&badcheater).signForm(*(Form *)&b);
			(*(Bureaucrat *)&cheater).signForm(*(Form *)&b);
			(*(Bureaucrat *)&cheater).signForm(*(Form *)&b);
			notcheater.signForm(*(Form *)&wasItEvenSigned);
			std::cout << d << std::endl;
			notcheater.signForm(d);
			std::cout << d << std::endl;
			std::cout << *(Form *)&wasItEvenSigned << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
