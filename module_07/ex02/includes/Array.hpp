/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:26:34 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/19 17:40:19 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

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