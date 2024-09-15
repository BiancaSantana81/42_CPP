// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t; // Array of objects of type Account
	typedef std::vector<int>								  ints_t; // Array of objects of type Int
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; // Pair of iterators: one for accounts_t and one for ints_t

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 }; /// Array of integers (amounts)
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) ); // Define size of 'amounts' (number of elements)
	accounts_t				accounts( amounts, amounts + amounts_size ); // Create and initialize 'accounts_t' vector with values from 'amounts'
	accounts_t::iterator	acc_begin	= accounts.begin(); // Iterator pointing to the beginning of 'accounts'
	accounts_t::iterator	acc_end		= accounts.end(); // Iterator pointing to the end of 'accounts'

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 }; // Array of integers (deposits)
	size_t const		d_size( sizeof(d) / sizeof(int) ); // Define size of 'd' (number of elements)
	ints_t				deposits( d, d + d_size ); // Create and initialize 'ints_t' vector with values from 'd'
	ints_t::iterator	dep_begin	= deposits.begin(); // Iterator pointing to the beginning of 'deposits'
	ints_t::iterator	dep_end		= deposits.end(); // Iterator pointing to the end of 'deposits'

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 }; // Array of integers (withdrawals)
	size_t const		w_size( sizeof(w) / sizeof(int) ); // Define size of 'w' (number of elements)
	ints_t				withdrawals( w, w + w_size ); // Create and initialize 'ints_t' vector with values from 'w'
	ints_t::iterator	wit_begin	= withdrawals.begin(); // Iterator pointing to the beginning of 'withdrawals'
	ints_t::iterator	wit_end		= withdrawals.end(); // Iterator pointing to the end of 'withdrawals'

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
