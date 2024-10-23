/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:44:59 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/23 16:51:56 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Span.hpp"

int main() {
    try {
        // Teste básico com 5 números
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        // Tentativa de adicionar mais um número além do limite
        std::cout << "Trying to add another number..." << std::endl;
        sp.addNumber(42);  // Deve lançar exceção
    } 
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        // Teste com menos de 2 números no container
        Span sp2(3);
        sp2.addNumber(10);

        std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;  // Deve lançar exceção
    } 
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        // Teste com um grande número de elementos
        Span sp3(10000);
        for (int i = 0; i < 10000; ++i) {
            sp3.addNumber(i);
        }

        std::cout << "Shortest Span (large set): " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest Span (large set): " << sp3.longestSpan() << std::endl;
    } 
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}