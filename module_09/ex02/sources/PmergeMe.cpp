/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:01:16 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/08 10:23:35 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* Constructors */

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &other)
: _dequeContainer(other._dequeContainer),
_vectorContainer(other._vectorContainer) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _dequeContainer = other._dequeContainer;
        _vectorContainer = other._vectorContainer;
    }
    return (*this);
}

/* DESTRUCTOR */

PmergeMe::~PmergeMe(void) {}