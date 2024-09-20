/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:57:36 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/20 15:01:07 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* CONSTRUTOR PADRÃO */

Fixed::Fixed(void) : _value(0)
{
    std::cout << "Default constructor called." << std::endl;
}

/* CONSTRUTOR DE CÓPIA */

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = other; // *this é uma referência ao próprio objeto, é uma instância de Fixed -> cópia é realizada através do operador de atribuição (operator=)
}

/* OUTRA FORMA DE CRIAR CONSTRUTOR DE CÓPIA */

// Fixed::Fixed(const Fixed &other): _value(other._value)
// {
//     std::cout << "Copy constructor called." << std::endl;
// }

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other)
        _value = other.getRawBits();
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same value." RESET <<std::endl;
    return (*this); // retorna uma referência ao objeto atual
}

Fixed::~Fixed()
{
    std::cout << "Destructor called." << std::endl;
}
    
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