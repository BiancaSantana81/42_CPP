/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:26:34 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/21 17:30:37 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
    
    T           *_elements;
    unsigned int _size;

    public:

    // constructors
    
    Array(void);
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(Array const &other);
    
    // métodos

    T &operator[](unsigned int index);
    unsigned int size() const;
    
    // destrutor
    ~Array(void);
};

#include "Array.tpp"

#endif