/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 09:34:45 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/15 11:47:49 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/tests.hpp"

void invalidSituations(void)
{
    std::cout << BRIGHT_YELLOW "========= invalid situations =========" RESET << std::endl;
    try {
        std::cout << BRIGHT_CYAN "=== Test 1: bucrocrat with grade -42 === " RESET << std::endl;
        Bureaucrat invalid1("lower", -42);
    } catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << BRIGHT_CYAN "=== Test 2: bucrocrat with grade 151 === " RESET << std::endl;
        Bureaucrat invalid2("high", 151);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << BRIGHT_CYAN "=== Test 3: Bureaucrat wants to achieve an impossible job === " RESET << std::endl;
        Bureaucrat invalid3("Senior", 1);
        invalid3.upGrade();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << BRIGHT_CYAN "=== Test 4: It can't go any lower === " RESET << std::endl;
        Bureaucrat invalid4("Intern", 150);
        invalid4.downGrade();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
    std::cout << BRIGHT_CYAN "=== Test 5: rising beyond the limits  === " RESET << std::endl;

    Bureaucrat invalid5("Carla", 50);
    std::cout << invalid5 << std::endl;

    for (; invalid5.getGrade() >= 1;) {
        invalid5.upGrade();
    }

    } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std::endl;
    }
}

void validSituations(void)
{
    std::cout << BRIGHT_YELLOW "========= valid situations =========" RESET << std::endl;
    std::cout << BRIGHT_CYAN "=== Test 1: Mid-level === " RESET << std::endl;
    Bureaucrat valid("Júlia", 50);
    std::cout << valid << std::endl;
    
    try {
    std::cout << BRIGHT_CYAN "=== Test 2: Bureaucrat at the lowest valid grade (150) === " RESET << std::endl;
    Bureaucrat john("Intern", 150);
    std::cout << john << std::endl;
    } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    }


    std::cout << BRIGHT_CYAN "=== Test 3: decreases in grade === " RESET << std::endl;
    valid.downGrade();
    std::cout << valid << std::endl;

    std::cout << BRIGHT_CYAN "=== Test 4: has reached the highest position! === " RESET << std::endl;
    for (; valid.getGrade() > 1; ) {
    valid.upGrade();
    std::cout << valid << std::endl;
    }

    std::cout << BRIGHT_CYAN "=== Test 5: Copy === " RESET << std::endl;
    
    Bureaucrat newMidle;
    newMidle = valid;
    std::cout << newMidle << std::endl;
}