/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:12:06 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/23 18:37:41 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/* CONSTRUCTORS */

template <typename T>
MutantStack<T>::MutantStack(void) {};

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other) {};


template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack<T> const &other)
{
    if (this != &other)
        std::stack<T>::operator=(other);
    return *this;
}

/* ITERATORS */

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
    return this->c.end();
}

/* DESTRUCTOR */

template <typename T>
MutantStack<T>::~MutantStack(void) {};
