/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:01:07 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/18 12:03:47 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ScalarConveter.hpp"

int main(void)
{   
    std::string input;

    std::cout << "Enter a literal to convert: ";
    std::getline(std::cin, input);

    ScalarConveter::convert(input);

    return (0);
}