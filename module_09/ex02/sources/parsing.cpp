/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:25:39 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/08 11:36:24 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

bool PmergeMe::validNumber(std::string input)
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

    for (std::deque<int>::iterator it = _dequeContainer.begin(); it != _dequeContainer.end(); ++it)
    {
        if (*it == intNumber)
        {
            std::cout << BRIGHT_RED "Error: Duplicate number found: " RESET << intNumber << std::endl;
            return false;
        }
    }
    return (true);
}

bool PmergeMe::parsing(int argc, char **argv)
{
    if (argc == 1 || argc > 3001)
    {
        std::cout << BRIGHT_RED "Error: number of invalid arguments." RESET << std::endl;
        return(false);
    }
    
    for (int i = 1; i < argc; i++)
    {
        if (!validNumber(argv[i]))
            return (false);
    }

    return (true);
}
