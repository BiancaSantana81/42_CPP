/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:52:52 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/21 10:40:21 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Serializer.hpp"
#include "includes/Data.hpp"

int main(void)
{
    Data types; 
    Data *ptr = &types;

    types.phrase = "heeeeey?!";

    std::cout << BRIGHT_CYAN "===== Test 1: Print original pointer value ====" RESET << std::endl;

    std::cout << "Pointer value before convert (original pointer): " << ptr << std::endl;
    std::cout << "Original value:" << ptr->phrase << std::endl;

    std::cout << BRIGHT_CYAN  "===== Test 2: Convert value in int with serializer  ====" RESET  << std::endl;
    uintptr_t raw = Serializer::serialize(&types);
    std::cout << "Serialized (pointer) value - after convert: " << raw << std::endl;

    std::cout << BRIGHT_CYAN  "===== Test 3: Convert value in pointer with deserializer  ====" RESET << std::endl;
    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Pointer value after convert: " << deserializedPtr << std::endl;
    std::cout  << deserializedPtr->phrase << std::endl;

    std::cout << BRIGHT_CYAN " ===== Test 4: Testing with null ===== " RESET << std::endl;
    Data *nothingHere = NULL;

    std::cout << "Pointer value before convert: " << nothingHere << std::endl;

    uintptr_t raw2 = Serializer::serialize(nothingHere);

    std::cout << "Serialized (pointer) value - after convert: " << raw2 << std::endl;

    //std::cout << nothingHere->phrase << std::endl; // segmentation fault: we cannot access an invalid memory value

    std::cout << BRIGHT_CYAN "\n===== Test 5: Testing invalid pointer ====" RESET << std::endl;
    Data *invalidPtr = reinterpret_cast<Data*>(0xdeadbeef);

    std::cout << "Pointer value before convert: " << invalidPtr << std::endl;

    uintptr_t rawInvalid = Serializer::serialize(invalidPtr);

    std::cout << "Serialized (pointer) value - after convert: " << rawInvalid << std::endl;
    
    Data *deserializedInvalidPtr = Serializer::deserialize(rawInvalid);

    std::cout << "Pointer value after serializer: " << deserializedInvalidPtr << std::endl;

    //invalidPtr->phrase = "Error: this pointer is invalid."; // segmentation fault: this memory address is invalid.

    return (0);
}