/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:54:05 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/11 11:11:47 by bsantana         ###   ########.fr       */
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

    rpnCalculator.calculate(argv[1]);

    return (0);
}