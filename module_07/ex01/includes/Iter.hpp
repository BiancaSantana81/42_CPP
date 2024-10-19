/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:08:20 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/19 13:41:17 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/* Valor constante é passado pela função chamada por iter - ela não pode modificar a matriz! */
template <typename T>
void iter(T *array, int size, void (*f)(T const &))
{
    for (int i= 0; i < size; i++)
        f(array[i]);
}

/* A função chamada por iter pode modificar o valor da matriz */

template <typename T>
void iter(T *array, int size, void(*f)(T &))
{
    for (int i= 0; i < size; i++)
        f(array[i]);
}

template <typename T>
void printMatrix(T const &elem)
{
    std::cout << elem << " ";
}

template <typename T>
void incrementMatrix(T &elem)
{
    ++elem;
}

#endif