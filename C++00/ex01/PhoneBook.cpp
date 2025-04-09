/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:03:30 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/04/09 11:03:31 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static void	replaceTabsNonPrintable(std::string *input)
{
	size_t	i;

	i = 0;
	while ((i = input->find('\t', i)) != std::string::npos)
	{
		input->replace(i, 1, "    ");
		i += 4;
	}
	for (std::string::iterator iter = input->begin(); iter != input->end(); iter++)
		if (*iter < ' ' || *iter == 127)
			*iter = ' ';
}

static char	isDigit(std::string input)
{
	for (std::string::iterator iter = input.begin(); iter != input.end(); iter++)
		if (!std::isdigit(*iter))
			return (0);
	return (1);
}

PhoneBook::PhoneBook(void)
{
	this->index = 0;
}

void	PhoneBook::add(void)
{
	std::string	input;

	while (1)
	{
		std::cout << "\e[33;1m- First Name -\e[0m\n";
		if (!std::getline(std::cin, input))
		{
			gEOF = 1;
			std::cout << "\e[35;1mEOF found. Exiting program.\e[0m\n";
			return ;
		}
		if (input.size() > 0)
			break ;
		std::cout << "\e[31;1mInvalid entry.\e[0m\n";
	}
	replaceTabsNonPrintable(&input);
	(this->contacts + this->index)->set("fname", input);
/* ********************************************************************************************************** */
	while (1)
	{
		std::cout << "\e[33;1m- Last Name -\e[0m\n";
		if (!std::getline(std::cin, input))
		{
			gEOF = 1;
			std::cout << "\e[35;1mEOF found. Exiting program.\e[0m\n";
			return ;
		}
		if (input.size() > 0)
			break ;
		std::cout << "\e[31;1mInvalid entry.\e[0m\n";
	}
	replaceTabsNonPrintable(&input);
	(this->contacts + this->index)->set("lname", input);
/* ********************************************************************************************************** */
	while (1)
	{
		std::cout << "\e[33;1m- Nickname -\e[0m\n";
		if (!std::getline(std::cin, input))
		{
			gEOF = 1;
			std::cout << "\e[35;1mEOF found. Exiting program.\e[0m\n";
			return ;
		}
		if (input.size() > 0)
			break ;
		std::cout << "\e[31;1mInvalid entry.\e[0m\n";
	}
	replaceTabsNonPrintable(&input);
	(this->contacts + this->index)->set("nname", input);
/* ********************************************************************************************************** */
	while (1)
	{
		std::cout << "\e[33;1m- Phone Number -\e[0m\n";
		if (!std::getline(std::cin, input))
		{
			gEOF = 1;
			std::cout << "\e[35;1mEOF found. Exiting program.\e[0m\n";
			return ;
		}
		if (input.size() > 0  && isDigit(input))
			break ;
		std::cout << "\e[31;1mInvalid entry.\e[0m\n";
	}
	replaceTabsNonPrintable(&input);
	(this->contacts + this->index)->set("phone", input);
/* ********************************************************************************************************** */
	while (1)
	{
		std::cout << "\e[33;1m- Darkest Secret -\e[0m\n";
		if (!std::getline(std::cin, input))
		{
			gEOF = 1;
			std::cout << "\e[35;1mEOF found. Exiting program.\e[0m\n";
			return ;
		}
		if (input.size() > 0)
			break ;
		std::cout << "\e[31;1mInvalid entry.\e[0m\n";
	}
	replaceTabsNonPrintable(&input);
	(this->contacts + this->index)->set("darkestSecret", input);
/* ********************************************************************************************************** */
	std::cout << "\e[32;1mEverything is saved !\e[0m\n";
	++this->index;
}

static void	printContactList(Contact contacts[8])
{
	char		i;
	std::string	tmp;

	std::cout << "\e[35;1m|III\e[0m--\e[35;1m/\e[0m++\e[33;1mII\e[0m++\e[35;1m\\\e[0m-++-\e[35;1m/\e[33;1mAA\e[0m--\e[32;1mAA\e[35;1m/\\\e[32;1mAA\e[0m--\e[33;1mAA\e[35;1m\\\e[0m-++-\e[35;1m/\e[0m++\e[33;1mII\e[0m++\e[35;1m\\\e[0m--\e[35;1mIII|\e[0m\n";
	std::cout << "\e[35;1m|II\e[0m--\e[35;1m<\e[0m-++\e[33;1mII\e[0m++-\e[35;1m>\e[0m++\e[35;1m<\e[0m-\e[33;1mXX\e[0m--\e[32;1mVVXXVV\e[0m--\e[33;1mXX\e[0m-\e[35;1m>\e[0m++\e[35;1m<\e[0m-++\e[33;1mII\e[0m++-\e[35;1m>\e[0m--\e[35;1mII|\e[0m\n";
	std::cout << "\e[35;1m|I\e[0m----\e[35;1m\\\e[0m++\e[33;1mII\e[0m++\e[35;1m/\e[0m-++-\e[35;1m\\\e[33;1mVV\e[0m--\e[32;1m||\e[35;1mWW\e[32;1m||\e[0m--\e[33;1mVV\e[35;1m/\e[0m-++-\e[35;1m\\\e[0m++\e[33;1mII\e[0m++\e[35;1m/\e[0m----\e[35;1mI|\e[0m\n";
	std::cout << "\e[35;1m|>\e[0m - \e[32;1m-|>\e[0m \e[34;1mFIRST NAME\e[0m \e[36;1m<|>\e[0m \e[36;1mLAST  NAME\e[0m \e[36;1m<|>\e[0m \e[34;1m NICKNAME \e[0m \e[35;1m<|\e[0m\n";
	std::cout << "\e[35;1m|>\e[0m - \e[32;1m-|>\e[0m \e[34;1m----------\e[0m \e[36;1m<|>\e[0m \e[36;1m----------\e[0m \e[36;1m<|>\e[0m \e[34;1m----------\e[0m \e[35;1m<|\e[0m\n";
/* ********************************************************************************************************** */
	i = -1;
	while (++i < 8)
	{
		std::cout << "\e[35;1m|>\e[0m " << (int)i << " \e[32;1m-|>\e[0m ";
/* ********************************************************************************************************** */
		tmp = (contacts + i)->get("fname");
		if (tmp.size() > 10)
			std::cout << "\e[34;1m" << tmp.substr(0, 9) << ".\e[0m \e[36;1m<|>\e[0m ";
		else if (tmp.size() < 10)
		{
			tmp = std::string(10 - tmp.size(), ' ') + tmp;
			std::cout << "\e[34;1m" << tmp << "\e[0m \e[36;1m<|>\e[0m ";
		}
		else
			std::cout << "\e[34;1m" << tmp << "\e[0m \e[36;1m<|>\e[0m ";
/* ********************************************************************************************************** */
		tmp = (contacts + i)->get("lname");
		if (tmp.size() > 10)
			std::cout << "\e[36;1m" << tmp.substr(0, 9) << ".\e[0m \e[36;1m<|>\e[0m ";
		else if (tmp.size() < 10)
		{
			tmp = std::string(10 - tmp.size(), ' ') + tmp;
			std::cout << "\e[36;1m" << tmp << "\e[0m \e[36;1m<|>\e[0m ";
		}
		else
			std::cout << "\e[36;1m" << tmp << "\e[32;1m \e[36;1m<|>\e[0m ";
/* ********************************************************************************************************** */
		tmp = (contacts + i)->get("nname");
		if (tmp.size() > 10)
			std::cout << "\e[34;1m" << tmp.substr(0, 9) << ".\e[0m \e[35;1m<|\e[0m\n";
		else if (tmp.size() < 10)
		{
			tmp = std::string(10 - tmp.size(), ' ') + tmp;
			std::cout << "\e[34;1m" << tmp << "\e[0m \e[35;1m<|\e[0m\n";
		}
		else
			std::cout << "\e[34;1m" << tmp << "\e[0m \e[35;1m<|\e[0m\n";
/* ********************************************************************************************************** */
	}
	std::cout << "\e[35;1m|I\e[0m----\e[35;1m/\e[0m++\e[33;1mII\e[0m++\e[35;1m\\\e[0m-++-\e[35;1m/\e[33;1mAA\e[0m--\e[32;1m||\e[35;1mMM\e[32;1m||\e[0m--\e[33;1mAA\e[35;1m\\\e[0m-++-\e[35;1m/\e[0m++\e[33;1mII\e[0m++\e[35;1m\\\e[0m----\e[35;1mI|\e[0m\n";
	std::cout << "\e[35;1m|II\e[0m--\e[35;1m<\e[0m-++\e[33;1mII\e[0m++-\e[35;1m>\e[0m++\e[35;1m<\e[0m-\e[33;1mXX\e[0m--\e[32;1mAAXXAA\e[0m--\e[32;1mXX\e[0m-\e[35;1m>\e[0m++\e[35;1m<\e[0m-++\e[33;1mII\e[0m++-\e[35;1m>\e[0m--\e[35;1mII|\e[0m\n";
	std::cout << "\e[35;1m|III\e[0m--\e[35;1m\\\e[0m++\e[33;1mII\e[0m++\e[35;1m/\e[0m-++-\e[35;1m\\\e[33;1mVV\e[0m--\e[32;1mVV\e[35;1m\\/\e[32;1mVV\e[0m--\e[33;1mVV\e[35;1m/\e[0m-++-\e[35;1m\\\e[0m++\e[33;1mII\e[0m++\e[35;1m/\e[0m--\e[35;1mIII|\e[0m\n";
}

static void	printContact(Contact contact)
{
	std::cout << "\e[32;1mFirst Name:\e[0m " << contact.get("fname")
		<< "\n\e[32;1mLast Name:\e[0m " << contact.get("lname")
		<< "\n\e[32;1mNickname:\e[0m " << contact.get("nname")
		<< "\n\e[32;1mPhone Number:\e[0m " << contact.get("phone")
		<< "\n\e[32;1mDarkest Secret:\e[0m " << contact.get("darkestSecret") << '\n';
}

void	PhoneBook::search(void)
{
	std::string	tmp;

	printContactList(this->contacts);
	while (1)
	{
		std::cout << "\e[36;1mWhich contact would you like to check? (0-7)\e[0m\n";
		if (!std::getline(std::cin, tmp))
		{
			gEOF = 1;
			std::cout << "\e[35;1mEOF found. Exiting program.\e[0m\n";
			return ;
		}
		if (tmp.size() != 1 || (*tmp.c_str() < '0' || *tmp.c_str() > '7'))
			std::cout << "\e[31;1mInvalid index.\e[0m\n";
		else
			return (printContact(*(this->contacts + *tmp.c_str() - '0')));
	}
}
