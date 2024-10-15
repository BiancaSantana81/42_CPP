/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:08:04 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/15 11:42:45 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/Intern.hpp"

void validSituations(void)
{
    std::cout << BRIGHT_YELLOW "====== valid situations tests ======  " RESET << std::endl;
    Intern nobody;

    std::cout << BRIGHT_CYAN "====== Test 1: create a presidential pardon ======  " RESET << std::endl;
    AForm *base;

    base = nobody.makeForm("presidential pardon", "sorry");

    std::cout << BRIGHT_CYAN "====== Test 2: create a robotomy request ======  " RESET << std::endl;
    AForm *base1;

    base1 = nobody.makeForm("robotomy request", "robo");

    std::cout << BRIGHT_CYAN "====== Test 3: create a  shubbery creation ======  " RESET << std::endl;
    AForm *base2;

    base2 = nobody.makeForm("shubbery creation", "home");

    std::cout << BRIGHT_CYAN " ----------------- clean memory ------------------  " RESET << std::endl;
    delete base;
    delete base1;
    delete base2;
}

void invalidSituations(void)
{
    std::cout << BRIGHT_YELLOW "====== invalid situations tests ======  " RESET << std::endl;
    Intern nobody;

    nobody.makeForm("noName", "home");
}

int main(void)
{
    validSituations();
    invalidSituations();
    return (0);
}

// int main(void)
// {
//     Intern someRandomIntern;
//     AForm* rrf;
    
//     rrf = someRandomIntern.makeForm("robotomy request", "Bender");
//     delete rrf;
//     return (0);
// }
