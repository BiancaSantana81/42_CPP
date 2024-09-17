/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:50:51 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 18:50:07 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

bool processInput(int argc, char **argv, std::ifstream &input, std::ofstream &output, std::string &s1, std::string &s2)
{
    if (argc != 4)
    {
        std::cout << RED "Error! Use: " RESET << argv[0] << " fileName <s1> <s2>" << std::endl; 
        return (false);
    }
    std::string inputFile = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    std::string outputFile = inputFile + ".replace";

    input.open(inputFile.c_str());
    if (!input.is_open())
    {
        std::cout << RED " Error opening input file!" RESET << std::endl;
        return (false);
    }

    output.open(outputFile.c_str());
    if (!output.is_open())
    {
        std::cout << RED " Error opening output file!" RESET << std::endl;
        input.close();
        return (false);
    }
    return (true);
}

void replace(std::ifstream &input, std::ofstream &output, const std::string &s1, const std::string &s2)
{
    std::string line;
    std::size_t pos = 0;

    if (s1.empty())
    {
        std::cerr << RED "The search string s1 cannot be empty." RESET << std::endl;
        return;
    }
    while (std::getline(input, line))
    {
        pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.replace(pos, s1.length(), s2);
            pos += s2.length();
        }
        output << line << std::endl; // escrever o conteúdo de line em .replace
    }
}