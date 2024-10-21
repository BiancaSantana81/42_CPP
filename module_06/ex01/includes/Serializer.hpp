/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:32:20 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/21 10:32:55 by bsantana         ###   ########.fr       */
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

// By making the constructors and destructor private, we ensure that the class cannot be instantiated or copied.
// This forces the class to be used only as a collection of static methods.

class Serializer
{
    private:

    // Private constructors and destructors to avoid creating instances

    Serializer(void);
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer(void);

    public:

    // Static methods for manipulating data without an instance

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif