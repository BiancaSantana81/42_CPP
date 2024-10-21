/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:32:24 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/21 10:49:41 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

/* 
   reinterpret_cast permite a conversão entre tipos não relacionados, como entre (void*) e int. 
   Esse tipo de conversão é útil para manipulação de ponteiros ou acesso a dados de baixo nível.
   No entanto, deve ser utilizado com extrema cautela, pois pode causar comportamento indefinido 
   e erros difíceis de detectar (como um segmentation fault no teste 5 do meu programa). 
   No teste 5, uma conversão inválida de ponteiro foi realizada, resultando em um endereço 
   de memória inválido que não pode ser acessado com segurança.
*/

/* CONSTRUCTORS */

Serializer::Serializer(void)
{
    std::cout << "Default constructor called." << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return (*this);
}

/* TYPE CONVERSION METHODS */

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

/* DESTRUCTOR */

Serializer::~Serializer(void)
{
    std::cout << "Default destructor called." << std::endl;
}
