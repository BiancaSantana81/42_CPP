/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:39:51 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/19 17:16:21 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <iostream>
#include <exception>

/* CONSTRUCTORS */

template <typename T>
Array<T>::Array(void): _elements(NULL), _size(0) {};

template <typename T>
Array<T>::Array(unsigned int n): _elements(new T[n]()), _size(n) {};

template <typename T>
Array<T>::Array(const Array &other): _elements(NULL), _size(other._size)
{
    if (_size > 0)
    {
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _elements[i] = other._elements[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] _elements;

        _size = other._size;
        _elements = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _elements[i] = other._elements[i];
    }
    return (*this);
}

/* METHODS */

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size) {
        throw std::exception();
    }
    return (_elements[index]);
}

// template <typename T>
// const T &Array<T>::operator[](unsigned int index)
// {
//      if (index >= _size) {
//         throw throw std::exception();
//     }
//     return (_elements[index]);
// }

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

/* DESTRUCTOR */

template <typename T>
Array<T>::~Array(void)
{
    delete _elements;
}

#endif