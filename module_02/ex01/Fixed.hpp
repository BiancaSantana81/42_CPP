/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:57:39 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/20 15:00:44 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#define BRIGHT_RED    "\033[91m"
#define RESET   "\033[0m"

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:

    int              _value;
    static const int _bits;

    public:
    
    Fixed(void);
    Fixed(const Fixed& other); // Construtor de cópia
    Fixed &operator=(const Fixed &other); // Operador de atribuição de cópia
    ~Fixed(void);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
        
};

#endif