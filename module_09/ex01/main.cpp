/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:54:05 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/06 11:20:56 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << BRIGHT_RED "Usage: ./RPN \"<expression>\"" RESET << std::endl;
        return (1);
    }

    RPN rpnCalculator;
    std::string input = argv[1];

    rpnCalculator.calculate(input);

    return (0);
}