/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:57:36 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/25 11:55:11 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/****************************************************************************/
/*                 Constructors and Copy Operator                           */
/****************************************************************************/

Fixed::Fixed(void) : _value(0)
{
    return ;
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

/****************************************************************************/
/*                   Constructors for Int and Float                         */
/****************************************************************************/

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        _value = other.getRawBits();
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same value." RESET <<std::endl;
    return (*this);
}

Fixed::Fixed(const int intValue)
{
    _value = intValue << _bits;
}
Fixed::Fixed(const float floatValue)
{
    _value = roundf(floatValue * 256);
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
    this->_value = raw;
}

/****************************************************************************/
/*                        Functions for converting values                   */
/****************************************************************************/

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> Fixed::_bits);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / 256);
}

/****************************************************************************/
/*                   Overload operator to print in float                    */
/****************************************************************************/

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

/****************************************************************************/
/*                          Comparison Operators                            */
/****************************************************************************/

bool Fixed::operator>(const Fixed &other) const
{
    return _value > other._value;
}

bool Fixed::operator<(const Fixed & other) const
{
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return _value != other._value;
}

/****************************************************************************/
/*                          Arithmetic operators                            */
/****************************************************************************/

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;

    result.setRawBits(_value + other._value);
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;

    result.setRawBits(_value - other._value);
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
  
    result.setRawBits((_value * other._value) >> _bits); // Multiplication must be adjusted by the number of bits
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.getRawBits() == 0)
    {
        std::cout << "Error: division by zero!" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.setRawBits((_value << _bits) / other._value); // Performs fixed point division
    return (result);
}

/****************************************************************************/
/*                         Increment and decrement                          */
/****************************************************************************/

#include "Fixed.hpp"

Fixed& Fixed::operator++() // Pre-increment: increments the internal value _value before using it
{
    _value += 1;
    return *this;
}

// Post-decrement: stores the current value in a temporary variable and returns the original value (not decremented).
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() // Pre-increment: increments the internal value _value before using it
{
    _value -= 1;
    return *this;
}

// Post-decrement: stores the current value in a temporary variable and returns the original value (not decremented).
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return temp;
}

/****************************************************************************/
/*                    Functions that return min and max                     */
/****************************************************************************/

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

/****************************************************************************/
/*                            Destructor                                    */
/****************************************************************************/

Fixed::~Fixed()
{
    return ;
}
