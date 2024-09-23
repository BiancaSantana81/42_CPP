/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:57:39 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/23 16:12:00 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_MAGENTA "\033[95m"
#define RESET   "\033[0m"

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:

    int              _value;
    static const int _bits = 8;

    public:
    
    // Construtores e destrutores 
    Fixed(void); // construtor padrão
    Fixed(const Fixed& other); // Construtor de cópia
    Fixed(const int intValue); // Construtor para valor inteiro
    Fixed(const float floatValue); // Construtor para valor flutuante
    
    Fixed &operator=(const Fixed &other); // Operador de atribuição de cópia
    ~Fixed(void); // destrutor
    
    // Getter e setter
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    // Funções para converter valores
    float toFloat(void) const;
    int toInt(void) const;

    // Operadores de comparação
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed& other) const;
    
    // Operadores aritméticos
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Operadores de incremento/decremento
    Fixed &operator++(); // pré-incremento
    Fixed operator++(int); // Pós-incremento
    Fixed& operator--(); // Pré-decremento
    Fixed operator--(int); // Pós-decremento

    //Funções para encontrar o min e max
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif