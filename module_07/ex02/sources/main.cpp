/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:07:02 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/19 17:07:42 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "=== Testando Array Vazio ===" << std::endl;
        Array<int> emptyArray;
        std::cout << "Tamanho: " << emptyArray.size() << std::endl;

        std::cout << "\n=== Testando Array de 5 Elementos ===" << std::endl;
        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << "Elemento " << i << ": " << intArray[i] << std::endl;
        }

        std::cout << "\n=== Modificando Elemento ===" << std::endl;
        intArray[2] = 42;
        std::cout << "Elemento 2: " << intArray[2] << std::endl;

        std::cout << "\n=== Teste de Índice Fora dos Limites ===" << std::endl;
        std::cout << intArray[10] << std::endl;  // Deve lançar exceção
    } catch (const std::exception& e) {
        std::cerr << "Exceção: " << e.what() << std::endl;
    }

    return 0;
}
