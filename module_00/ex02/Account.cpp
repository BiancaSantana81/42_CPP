/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:25:14 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/15 16:38:30 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_GREEN  "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE   "\033[94m"
#define RESET   "\033[0m"


/* Initializing program variables*/

int Account::_nbAccounts = 0; // Counter for the total number of accounts created.
int Account::_totalAmount = 0; // Total sum of all balances (amounts) across all created accounts.
int Account::_totalNbDeposits = 0; // Total counter for all deposits made across all accounts.
int Account::_totalNbWithdrawals = 0; // Total counter for all withdrawals made across all accounts.

/* Constructor and Destructor */

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts++; // index current account.
    _amount = initial_deposit; // initial balance of the account with the value of the initial deposit.
    _totalAmount += initial_deposit; // total amount of money across all accounts.
    _nbDeposits = 0;  // number of deposits.
    _nbWithdrawals = 0; // number of withdrawals for this account to 0.

    _displayTimestamp();
    std::cout << BRIGHT_YELLOW "Index: [" << _accountIndex << "] " RESET
              << "Amount: [" << _amount << "] "
              << BRIGHT_GREEN "created" RESET << std::endl;
    return ;
}

Account::~Account(void)
{
    return ;
}

/* Getters of the program */

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

/* Functions class Account */

void Account::_displayTimestamp(void)
{
    std::time_t now;
    std::tm *local;

    now = std::time(NULL);
    local = std::localtime(&now);

    std::cout << "[";
    std::cout << 1900 + local->tm_year;
    std::cout << (local->tm_mon + 1 < 10 ? "0" : "") << local->tm_mon + 1;
    std::cout << (local->tm_mday < 10 ? "0" : "") << local->tm_mday << "_";
    std::cout << (local->tm_hour < 10 ? "0" : "") << local->tm_hour;
    std::cout << (local->tm_min < 10 ? "0" : "") << local->tm_min;
    std::cout << (local->tm_sec < 10 ? "0" : "") << local->tm_sec;
    std::cout << "] ";
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << BRIGHT_BLUE "accounts: " RESET << Account::getNbAccounts()
              << BRIGHT_BLUE" total: " RESET << Account::getTotalAmount()
              << BRIGHT_GREEN " deposits: " RESET << Account::getNbDeposits()
              << BRIGHT_RED " withdrawals: " RESET << Account::getNbWithdrawals()
              << std::endl;
}

void Account::makeDeposit(int deposit)
{
    (void)deposit;
    return ;
}

bool Account::makeWithdrawal(int withdrawal)
{
    (void)withdrawal;
    return (true);
}

int Account::checkAmount(void) const
{
    return (0);
}

void Account::displayStatus(void) const
{
    return ;    
}

