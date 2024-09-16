/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:47:49 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/16 10:52:34 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Megaphone
{
    public:

    void TransformString(std::string str)
    {
        for (size_t i = 0; i < str.length(); i++)
            str[i] = toupper(str[i]);
        std::cout << str;
    }
};

int main(int argc, char **argv)
{
    Megaphone megaphone;
    std::string argument;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i++)
        {
            argument = argv[i];
            megaphone.TransformString(argument);
        }
        std::cout << std::endl;
    }
    return (0);
}
