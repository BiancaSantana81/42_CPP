/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:17:18 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/19 15:19:55 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/* Constructor and Destructor */

Harl::Harl(void)
{
    std::cout << "Created the Harl!" << std::endl;
}

Harl::~Harl(void)
{
    std::cout << "Destroyed the Harl!" << std::endl;
}

/* Private methods: Harl complaints */

void Harl::debug(void)
{
    std::cout << RED "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" RESET
              << std::endl;
}

void Harl::info(void)
{
    std::cout << GREEN "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" RESET
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << YELLOW "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." RESET
              << std::endl;
}

void Harl::error(void)
{
    std::cout << BLUE "This is unacceptable! I want to speak to the manager now." RESET
              << std::endl;
}

/* Registering Harls complaints */

void Harl::complain(std:: string level)
{
    std::string current_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int i;

    for (i = 0; i < 4; i++)
    {
        if (level == current_level[i])
            break ;
    }
    switch (i)
    {
        case DEBUG_LEVEL:
            debug();
        case INFO_LEVEL:
            info();
        case WARNING_LEVEL:
            warning();
        case ERROR_LEVEL:
            error();
            break ;
        default:
            std::cout << RED "This is not a valid entry!" RESET << std::endl;
            break ;
    }
}