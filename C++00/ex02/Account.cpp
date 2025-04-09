/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:01:55 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/04/09 11:01:57 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	char		timestamp[20];
	std::time_t	time;

	time = std::time(NULL);
	std::strftime(timestamp, 20, "[%Y%m%d_%H%M%S] \0", std::localtime(&time));
	std::cout << timestamp;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = Account::getNbAccounts();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";created\n";
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";closed\n";
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbDeposits() << ";withdrawals:"
		<< Account::getNbWithdrawals() << '\n';
}

void	Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount - deposit
		<< ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:"
		<< this->_nbDeposits << '\n';
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits << ";withdrawals:"
		<< this->_nbWithdrawals << '\n';
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
		<< ";withdrawals:";
	if (this->checkAmount() < withdrawal)
	{
		std::cout << "refused\n";
		return (0);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:"
		<< this->_nbWithdrawals << '\n';
	return (1);
}
