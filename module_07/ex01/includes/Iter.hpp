/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:08:20 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/22 10:16:03 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/* Constant value is passed by the function called iter - it cannot modify the matrix! */
template <typename T>
void iter(T *array, int size, void (*f)(T const &))
{
    for (int i= 0; i < size; i++)
        f(array[i]);
}

/* The function called iter iterates and modifies the value of the matrix */
template <typename T>
void iter(T *array, int size, void(*f)(T &))
{
    for (int i= 0; i < size; i++)
        f(array[i]);
}

/* Test function: just prints the elements of the matrix */
template <typename T>
void printMatrix(T const &elem)
{
    std::cout << elem << " ";
}

/* Test function: increments (+1) the values in the matrix */
template <typename T>
void incrementMatrix(T &elem)
{
    ++elem;
}

#endif