/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:20:26 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/18 16:49:58 by bsantana         ###   ########.fr       */
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
    // Create an array with pointers to the claim functions.
    void(Harl::*complains[4])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    // Array of levels to traverse
    std::string current_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++)
    {
        if (level == current_level[i])
        {
            (this->*complains[i])();
            return ;
        }
    }
    std::cout << "Unknown level." << std::endl;
}
