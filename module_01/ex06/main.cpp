/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:15:06 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/19 15:18:49 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << RED "Add a valid entry!" RESET << std::endl;
        return (1);
    }

    Harl complainer;
    std::string option;

    option = argv[1];
    complainer.complain(option);
    return (0);
}