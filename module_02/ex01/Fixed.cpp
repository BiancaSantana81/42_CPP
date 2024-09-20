/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:57:36 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/20 16:14:32 by bsantana         ###   ########.fr       */
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


Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other)
        _value = other.getRawBits();
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same value." RESET <<std::endl;
    return (*this); // retorna uma referência ao objeto atual
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called." << std::endl;
    _value = intValue << _bits;
}
Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called." << std::endl;
    _value = roundf(floatValue * (1 << _bits));
}

/****************************************************************************/
/*                        Getter and Setter                                 */
/****************************************************************************/

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

/****************************************************************************/
/*                        Functions for converting values                   */
/****************************************************************************/

float Fixed::toFloat(void) const {
    // Divide o valor de ponto fixo pelo fator de escala para obter o float original
    return static_cast<float>(_bits) / (1 << _bits);
}

// Função que converte o valor de ponto fixo para inteiro
int Fixed::toInt(void) const {
    // Desloca à direita para remover a parte fracionária
    return _bits >> _bits;
}

/****************************************************************************/
/*                   Convert to fixed to floating point                     */
/****************************************************************************/

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

