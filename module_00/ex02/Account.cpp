/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:25:14 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/15 15:47:42 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_GREEN  "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define RESET   "\033[0m"


/* Initializing program variables*/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/* Constructor and Destructor */

Account::Account(int initial_deposit)
{
    (void)initial_deposit;
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

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

void Account::displayAccountsInfos(void)
{
    return ;
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

void Account::_displayTimestamp(void)
{
    return ;
}
