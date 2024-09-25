/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:02:06 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/24 11:53:11 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* DEFAULT CONSTRUCTOR */

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called." << std::endl;
}

/* COPY CONSTRUCTOR */

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = other; // *this is a reference to the object itself, it is an instance of Fixed -> copying is done using the assignment operator (operator=)
}

// /* COPY ASSIGNMENT OPERATOR  */

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other)
        _value = other.getRawBits();
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same address." RESET <<std::endl;
    return (*this);  // returns a reference to the current object
}

/* DEFAULT DESTRUCTOR */

Fixed::~Fixed()
{
    std::cout << "Destructor called." << std::endl;
}

/* GETTER AND SETTER */

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called." << std::endl;
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called." << std::endl;
    this->_value = raw;
}