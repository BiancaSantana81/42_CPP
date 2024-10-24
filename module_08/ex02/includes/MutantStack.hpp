/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:12:09 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/24 11:26:28 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <list>

// colors

#define BRIGHT_GREEN  "\033[92m"
#define BRIGHT_MAGENTA "\033[95m"
#define RESET   "\033[0m"

template <typename T>
class MutantStack : public std::stack<T>
{
    public:

    // constructors and destructor

    MutantStack(void);
    MutantStack(MutantStack const &other);
    MutantStack<T> &operator=(MutantStack<T> const &other);
    ~MutantStack(void);

    // iterators

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin(void);
    iterator end(void);

};

#include "MutantStack.tpp"

#endif