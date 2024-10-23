/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:39:59 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/23 19:17:47 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

static void basicTests(void);
static void listTests(void);

int main(void)
{
    std::cout << BRIGHT_MAGENTA "MUTANT STACK" RESET << std::endl;
    basicTests();
    std::cout << BRIGHT_MAGENTA "LIST" RESET << std::endl;
    listTests();
    return 0;
}

static void basicTests(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << BRIGHT_GREEN "top of the stack: " RESET << mstack.top() << std::endl;

    mstack.pop();

    std::cout << BRIGHT_GREEN "stack size after removing an element: " RESET << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    
    std::cout << BRIGHT_GREEN "browsing the elements of the stack... " RESET << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

static void listTests(void)
{
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);

    std::cout <<  BRIGHT_GREEN "top of the list: " RESET << mlist.back() << std::endl;
    std::cout <<  BRIGHT_GREEN "end of the list: " RESET << mlist.front() << std::endl;

    mlist.pop_back();

    std::cout <<  BRIGHT_GREEN "list size after removing an element: " RESET << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    
    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();

    std::cout <<  BRIGHT_GREEN "browsing the elements of the list... " RESET << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}