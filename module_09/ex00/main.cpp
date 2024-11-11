/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:24:53 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/11 10:45:38 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing.hpp"
#include "includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (!parsing(argc, argv))
        return (1);
    runProgram(std::string(argv[1]));
    return (0);
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
