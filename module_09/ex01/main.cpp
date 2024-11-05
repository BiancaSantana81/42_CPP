/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:54:05 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/05 16:34:06 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./RPN \"<expression>\"" << std::endl;
        return (1);
    }

    RPN rpnCalculator;
    std::string input = argv[1];

    rpnCalculator.calculate(input);

    // validar se há operandos e operadores o suficiente para realizar a operação (um número a mais que a quantidade de operadores)
    // notação polonesa invertida -> começar a adicionar na pilha, verificando é operando -> adiciona na pilha, não é retira os dois últimos e faz a operação.

    return (0);
}