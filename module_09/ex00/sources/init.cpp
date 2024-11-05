/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:30:06 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/05 14:25:05 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/init.hpp"

int parsing(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << BRIGHT_RED "Error! You should test with:" << BRIGHT_YELLOW " ./btc file.txt" RESET << std::endl;
        return (0);
    }
    
    if (!is_txt(argv[1]))
    {
        std::cout << BRIGHT_RED "Error! You should test with:" << BRIGHT_YELLOW " ./btc file.txt" RESET << std::endl;
        return (0);
    }
    return (1);
}

int is_txt(const char *filename)
{
    const char *ext = strrchr(filename, '.');
    return (ext && strcmp(ext, ".txt") == 0);
}

int runProgram(const std::string &filename)
{
    std::ifstream file(filename.c_str());

    if (!file)
    {
        std::cout << BRIGHT_RED "Error opening file! Try again with a valid file." << std::endl;
        return (1);
    }

    BitcoinExchange exchange;

    try {
        exchange.populatingContainer("data.csv");
        exchange.loadingData(file);
    } catch (const std::runtime_error &e) {
        std::cout << BRIGHT_RED "Exception: " << e.what() << std::endl;
        return (1);
    }
    return (0);
}
