/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:30:06 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/28 15:09:12 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/init.hpp"

int is_csv(const char *filename)
{
    const char *ext = strrchr(filename, '.');
    return (ext && strcmp(ext, ".csv") == 0);
}

int parsing(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << BRIGHT_RED "Error! You should test with:" << BRIGHT_YELLOW " ./btc file.csv" RESET << std::endl;
        return (0);
    }
    
    if (!is_csv(argv[1]))
    {
        std::cout << BRIGHT_RED "Error! You should test with:" << BRIGHT_YELLOW " ./btc file.csv" RESET << std::endl;
        return (0);
    }
    return (1);
}

int runProgram(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file)
    {
        std::cout << BRIGHT_RED "Error opening file! Try again with a valid file." << std::endl;
        return (1);
    }

    BitcoinExchange data;

    try {
        data.populatingContainer(file);
        
    } catch (const std::runtime_error &e) {
        std::cout << BRIGHT_RED "Exception: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}
