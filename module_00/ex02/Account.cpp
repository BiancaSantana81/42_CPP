/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:25:14 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/16 11:46:47 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
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
    _displayTimestamp();
    std::cout << BRIGHT_YELLOW "Index: [" << _accountIndex << "] " RESET
              << BRIGHT_BLUE "Amount: [" << _amount << "] " RESET
              << BRIGHT_YELLOW " closed. " RESET << std::endl;
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

int Account::checkAmount(void) const
{
    return this->_amount;
}

/* Functions class Account */

/**
 * @brief Displays the current timestamp in the format [YYYYMMDD_HHMMSS].
 *
 * Gets the current date and time and formats it for log display.
 */
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

/**
 * @brief Displays general information about all accounts.
 *
 * Shows the total number of accounts, the total amount, the total number of deposits,
 * and the total number of withdrawals, preceded by the current timestamp.
 */
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << BRIGHT_BLUE "accounts: " RESET << Account::getNbAccounts()
              << BRIGHT_BLUE" total: " RESET << Account::getTotalAmount()
              << BRIGHT_GREEN " deposits: " RESET << Account::getNbDeposits()
              << BRIGHT_RED " withdrawals: " RESET << Account::getNbWithdrawals()
              << std::endl;
}

/**
 * @brief Displays the status of the current account.
 *
 * Shows the account index, current balance, number of deposits, and number of withdrawals,
 * preceded by the current timestamp.
 */
void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << BRIGHT_YELLOW "Index: [" << _accountIndex << "] " RESET
              << BRIGHT_BLUE " amount: " RESET << _amount
              << BRIGHT_GREEN " deposits: " RESET << _nbDeposits
              << BRIGHT_RED " withdrawals: " RESET << _nbWithdrawals
              << std::endl;
}

/**
 * @brief Makes a deposit into the account and prints the transaction.
 *
 * Updates the account balance with the deposit amount, increments the deposit count,
 * and updates the total deposits and total amount. Prints a message detailing the
 * transaction, preceded by the current timestamp.
 *
 * @param deposit The amount to be deposited.
 */
void Account::makeDeposit(int deposit)
{
    int p_amount;

    p_amount = _amount;
    _displayTimestamp();
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    
    std::cout << BRIGHT_YELLOW "Index: [" << _accountIndex << "] " RESET
              << BRIGHT_RED" p_amount: " RESET << p_amount
              << BRIGHT_GREEN " deposit: " RESET << deposit
              << BRIGHT_YELLOW " amount: " RESET << _amount
              << BRIGHT_BLUE " nb_deposits: " RESET << _nbDeposits
              << std::endl;
}

/**
 * @brief Attempts to make a withdrawal from the account.
 *
 * Checks if the withdrawal amount is greater than the available balance.
 * If the withdrawal is refused, it displays a message and returns false.
 * Otherwise, it updates the balance, the total withdrawals, and logs the transaction.
 *
 * @param withdrawal Amount to be withdrawn.
 * @return bool Returns true if the withdrawal is successful, false otherwise.
 */
bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > this->checkAmount())
    {
        _displayTimestamp();
        std::cout << BRIGHT_YELLOW "Index: [" << _accountIndex << "] " RESET
                  << BRIGHT_BLUE " p_amount: " RESET << _amount
                  << BRIGHT_RED " withdrawal:refused!!! " RESET << std::endl;
        return (false);
    }
    else
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals += 1;
        _totalNbWithdrawals += 1;

         _displayTimestamp();
         std::cout << BRIGHT_YELLOW "Index: [" << _accountIndex << "] " RESET
                  << BRIGHT_BLUE " p_amount: " RESET << _amount + withdrawal
                  << BRIGHT_RED " withdrawal: " RESET << withdrawal
                  << BRIGHT_YELLOW " amount: " RESET << _amount
                  << BRIGHT_BLUE " nb_withdrawals: " RESET << _nbWithdrawals << std::endl;
        return (true);
    }
}
