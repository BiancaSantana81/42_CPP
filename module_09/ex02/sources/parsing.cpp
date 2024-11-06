/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:25:39 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/06 15:17:43 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.hpp"

bool validNumber(std::string input, int* uniqueNumbers, int& size)
{
    long number;
    std::istringstream iss(input);
    
    iss >> number;

    if (iss.fail() || !iss.eof())
    {
        std::cout << BRIGHT_RED "Error: non-numeric entry identified: " RESET << input << std::endl;
        return (false);
    }

    if (number < 0 || number > std::numeric_limits<int>::max())
    {
        std::cout << BRIGHT_RED "Error: value outside the INT range: " RESET << number << std::endl;
        return (false);
    }

    int intNumber = static_cast<int>(number);

    for (int i = 0; i < size; i++)
    {
        if (uniqueNumbers[i] == intNumber)
        {
            std::cout << BRIGHT_RED "Error: Duplicate number found: " RESET << intNumber << std::endl;
            return (false);
        }
    }

    uniqueNumbers[size] = intNumber;
    size++;

    return (true);
}

bool parsing(int argc, char **argv)
{
    if (argc == 1 || argc > 3001)
    {
        std::cout << BRIGHT_RED "Error: number of invalid arguments." RESET << std::endl;
        return(false);
    }

    int uniqueNumbers[3000];
    int size = 0;
    
    for (int i = 1; i < argc; i++)
    {
        if (!validNumber(argv[i], uniqueNumbers, size))
            return (false);
    }
    return (true);
}
