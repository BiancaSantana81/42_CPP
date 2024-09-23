/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:57:36 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/23 16:30:46 by bsantana         ###   ########.fr       */
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
    _value = intValue << _bits;
}
Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called." << std::endl;
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
    std::cout << "setRawBits member function called." << std::endl;
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
/*                   Convert to fixed to floating point                     */
/****************************************************************************/

// Sobrecarga do operador de saída (<<) para a classe Fixed.
// Permite imprimir objetos Fixed diretamente usando std::cout.
// Converte o valor armazenado em ponto fixo para ponto flutuante
// chamando o método toFloat(), garantindo que a representação
// seja legível como um número decimal.
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
  
    result.setRawBits((_value * other._value) >> _bits);   // Multiplicação deve ser ajustada pela quantidade de bits
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
    result.setRawBits((_value << _bits) / other._value);
    return (result);
}

/****************************************************************************/
/*                          Arithmetic operators                            */
/****************************************************************************/

#include "Fixed.hpp"

// Pré-incremento
Fixed& Fixed::operator++()
{
    _value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--()
{
    _value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this; // Armazena o valor atual
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
    std::cout << "Destructor called." << std::endl;
}
