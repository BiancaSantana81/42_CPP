/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:15:06 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/18 16:30:09 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl complainer;
    std::string option;

    if (argc != 2)
    {
        std::cout << "Enter just one level! " << std::endl;
        return (1);
    }
    option = argv[1];
    complainer.complain(option);
    return (0);
}