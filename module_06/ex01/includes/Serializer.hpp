/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:32:20 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/16 16:49:43 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_CYAN   "\033[96m"
#define RESET   "\033[0m"

#include "Data.hpp"

// Ao tornar os construtores e o destrutor privados, garantimos que a classe não possa ser instanciada ou copiada.
// Isso força o uso da classe apenas como um agrupamento de métodos estáticos.

class Serializer
{
    private:

    // Construtores e destrutor privados para evitar criação de instâncias

    Serializer(void);
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer(void);

    public:

    // Métodos estáticos para manipular dados sem instância

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif