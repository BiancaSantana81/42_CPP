/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:02:02 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/24 11:57:08 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_MAGENTA "\033[95m"
#define RESET   "\033[0m"

#include <iostream>
#include <string>

class Fixed
{
    private:

    int              _value;
    static const int _bits = 8;

    public:
    
    Fixed(void);
    Fixed(const Fixed& other); // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment operator
    ~Fixed(void);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
        
};

void runFixedTests(Fixed &a, Fixed &b, Fixed &c);
Fixed createFixedByValue(Fixed f);
void assignFixedByReference(Fixed& target, const Fixed& source);
Fixed returnFixedByValue();

#endif