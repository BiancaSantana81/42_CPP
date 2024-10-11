/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:34:45 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/11 09:55:39 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/tests.hpp"

void invalidSituations(void)
{
    std::cout << BRIGHT_YELLOW "========= invalid situations =========" RESET << std::endl;
    try {
        std::cout << BRIGHT_CYAN "=== Test 1: bucrocrat with grade -42" RESET << std::endl;
        Bureaucrat invalid1("lower", -42);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << BRIGHT_CYAN "=== Test 2: bucrocrat with grade 151" RESET << std::endl;
        Bureaucrat invalid2("high", 151);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
