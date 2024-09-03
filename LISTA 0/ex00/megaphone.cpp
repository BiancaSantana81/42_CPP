/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:47:49 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/03 18:42:23 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void megaphone(const std::string& str)
{
    std::cout << "Argumento: " << str << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "*LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    for (int i = 1; i < argc; i++)
    {
        std::string argument = argv[i];
        megaphone(argument);
    }
    return 0;
}