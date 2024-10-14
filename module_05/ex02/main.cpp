/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:08:04 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/14 15:29:10 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

void validSituations(void)
{
    return ;
}

void testCopyConstructor(void)
{
    return ;
}

void invalidSituations(void)
{
    return ;
}

int main(void)
{
    Bureaucrat alice("Alice", 2);
    PresidentialPardonForm sorry("Robert");

    //sorry.beSigned(alice);
    //std::cout << sorry << std::endl; 
    alice.executeForm(sorry);
    return (0);
}
