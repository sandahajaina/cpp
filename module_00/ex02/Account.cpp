/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:37:30 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/03 00:23:33 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts;
    _nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    _displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			<< "amount:"<< this->_amount << ";"
			<< "created" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << ";" << std::endl;
}

bool Account::makeWithdrawal(int withdrawl)
{
	int p_amount = this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "withdrawal:";
	if (p_amount - withdrawl < 0)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawl << ";";
	this->_amount -= withdrawl;
	_totalAmount -= withdrawl;
	_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
	return true;
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp(void)
{
    time_t  now = time(NULL);
    struct tm *lt = localtime(&now);
    std::cout << "[" << (lt->tm_year + 1900);
	if (lt->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << (lt->tm_mon + 1);
	if (lt->tm_mday < 10)
		std::cout << "0";
	std::cout << lt->tm_mday << "_";
	if (lt->tm_hour < 10)
		std::cout << "0";
	std::cout << (lt->tm_hour);
	if (lt->tm_min < 10)
		std::cout << "0";
	std::cout << (lt->tm_min);
	if (lt->tm_sec < 10)
		std::cout << "0";
	std::cout << (lt->tm_sec) << "] ";
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << ";" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:"<< this->_amount << ";"
		<< "closed" << std::endl;
}