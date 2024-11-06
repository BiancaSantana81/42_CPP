/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:25:39 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/06 16:57:17 by bsantana         ###   ########.fr       */
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

    _dequeContainer.push_back(intNumber);
    _vectorContainer.push_back(intNumber);

    return (true);
}

void PmergeMe::printValues(void)
{
    std::cout << BRIGHT_MAGENTA "unordered values: " RESET;
    for (size_t i = 0; i < _vectorContainer.size(); i++)
        std::cout << _vectorContainer[i] << " ";
    std::cout << std::endl;
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
    
    printValues();  
    return (true);
}
