/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:47:49 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/04 10:56:41 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void megaphone(std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
    std::cout << str << std::endl;
}

int main(int argc, char **argv)
{
    std::string argument;

    if (argc == 1)
        std::cout << "*LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    for (int i = 1; i < argc; i++)
    {
        argument = argv[i];
        megaphone(argument);
    }
    return 0;
}
