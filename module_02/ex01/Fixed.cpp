/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:57:36 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/23 15:28:49 by bsantana         ###   ########.fr       */
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
    _value = roundf(floatValue * 256); // descola para direita os bits de 1 (1 << _bits), multiplica pelo float e arredonda com a roundf
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
	return (this->getRawBits() >> Fixed::_bits); // desloca para esquerda oito bits para obter o valor inteiro
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->getRawBits()) / 256); // casting para converter ponto fixo para flutuante e depois divisão por 256 para dividir e retornar flutuante
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
/*                            Destructor                                    */
/****************************************************************************/

Fixed::~Fixed()
{
    std::cout << "Destructor called." << std::endl;
}

