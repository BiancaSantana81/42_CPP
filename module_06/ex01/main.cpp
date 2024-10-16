/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:52:52 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/16 17:30:32 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Serializer.hpp"
#include "includes/Data.hpp"

int main(void)
{
    Data types; 
    Data *ptr = &types;

    types.phrase = "We're converting the pointer value, not its content, okay?!";

    std::cout << BRIGHT_CYAN "===== Test 1: Print original pointer value ====" RESET << std::endl;

    std::cout << "Pointer value before convert: " << ptr << std::endl;
    uintptr_t raw = Serializer::serialize(&types);

    std::cout << BRIGHT_CYAN  "===== Test 2: Convert value in int with serializer  ====" RESET  << std::endl;
    std::cout << "Serialized (pointer) value: " << raw << std::endl;

    std::cout << BRIGHT_CYAN  "===== Test 3: Convert value in pointer with deserializer  ====" RESET << std::endl;
    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Pointer value after convert: " << deserializedPtr << std::endl;
    std::cout  << deserializedPtr->phrase << std::endl;

    std::cout << BRIGHT_CYAN " ===== Test 4: Testing with nullptr ===== " RESET << std::endl;
    Data *nothingHere = NULL;

    std::cout << "Pointer value after convert: " << nothingHere << std::endl;

    uintptr_t raw2 = Serializer::serialize(nothingHere);
    std::cout << "Pointer value before convert: " << raw2 << std::endl;

    std::cout << nothingHere->phrase << std::endl; // segmentation fault: we cannot access an invalid memory value

    return (0);
}