/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:57:36 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/24 15:47:58 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/****************************************************************************/
/*                 Constructors and Copy Operator                           */
/****************************************************************************/

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = other;
}

/****************************************************************************/
/*                   Constructors for Int and Float                         */
/****************************************************************************/

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other)
        _value = other.getRawBits();
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same value." RESET <<std::endl;
    return (*this);
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called." << std::endl;
    _value = intValue << _bits; // Shifts the bits to the left by 8 positions, equivalent to multiplying the value by 256 to store it as a fixed point
}
Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called." << std::endl;
    _value = roundf(floatValue * 256); // Multiplies the floating value by 256 and rounds to the nearest integer to store as a fixed point
}

/****************************************************************************/
/*                        Getter and Setter                                 */
/****************************************************************************/

int Fixed::getRawBits(void) const
{
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called." << std::endl;
    this->_value = raw;
}

/****************************************************************************/
/*                        Functions for converting values                   */
/****************************************************************************/

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> Fixed::_bits); // shifts left eight bits to get the integer value (fixed >> _bits)
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / 256);
    // Convert the value stored in _value from int to float and then divide by 256 to get the actual value in float.
    // e.g.: 512.0 / 256 = 2.0 (result is a float)
}

/****************************************************************************/
/*                   Convert to fixed to floating point                     */
/****************************************************************************/

// Overloading the insertion operator (<<) for the Fixed class.
// The toFloat() method is called to convert the stored fixed point value
// stored fixed point value (_value) into a floating point value,
// ensuring a precise and readable representation in decimal format.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

/****************************************************************************/
/*                            Destructor                                    */
/****************************************************************************/

Fixed::~Fixed()
{
    std::cout << "Destructor called." << std::endl;
}

