/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:57:39 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/24 15:33:25 by bsantana         ###   ########.fr       */
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

    // Constructors and destructors 
    Fixed(void);
    Fixed(const Fixed& other); // Copy constructor
    Fixed(const int intValue); // Constructor for integer value 
    Fixed(const float floatValue); // Floating value constructor
    
    Fixed &operator=(const Fixed &other);  // Copy assignment operator
    ~Fixed(void);

    // Getter e setter
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Functions to convert values
    float toFloat(void) const;
    int   toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif