/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/11 11:09:28 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <climits>
#include <string>
#include <sstream>
#include <stack>

#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_RED    "\033[91m"
#define RESET   "\033[0m"

class RPN
{
    private:

    /*
        Esta classe utiliza o container `stack` para armazenar valores, 
        facilitando o cálculo de uma expressão em Notação Polonesa Reversa (RPN).
        A escolha do `stack` permite acesso rápido ao elemento no topo, 
        ideal para a retirada dos operandos mais recentes, o que simplifica 
        a implementação do algoritmo de RPN ao seguir o fluxo natural da pilha 
        (último a entrar, primeiro a sair - LIFO).
    */

    std::stack<int> _values;

    public:

    //constructors and destructor

    RPN(void);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN(void);

    // methods

    void calculate(std::string input);
    int performingOperation(std::string token, int a, int b);

    bool validInput(std::string line);
    bool isOperator(std::string token);
    bool isNumber(std::string token);

    int convertNumber(std::string token);

};

#endif