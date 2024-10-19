/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:26:34 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/19 17:31:29 by bsantana         ###   ########.fr       */
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
    
    Array(void); // construtor padrão
    Array(unsigned int n); // construtor parametrizado
    Array(const Array &other); // construtor de cópia
    Array &operator=(Array const &other); // atribuição por cópia
    
    // métodos

    T &operator[](unsigned int index);
    unsigned int size() const;
    
    // destrutor
    ~Array(void);
};

#include "Array.tpp"

#endif