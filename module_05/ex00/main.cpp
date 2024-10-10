/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:08:04 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/10 18:12:11 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"


void lowerGradeEntry(void)
{
    try {
        Bureaucrat invalid1("Andrey", -42);
    }
    catch (const Bureaucrat::GradeTooHighExeception &e)
    {
        std::cerr << "Exception " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowExeception &e)
    {
        std::cerr << "Exception " << e.what() << std::endl;
    }
}

void highGradeEntry(void)
{
    try {
        Bureaucrat invalid1("Andrey", 151);
    }
    catch (const Bureaucrat::GradeTooHighExeception &e)
    {
        std::cerr << "Exception " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowExeception &e)
    {
        std::cerr << "Exception " << e.what() << std::endl;
    }
}

int main(void)
{
    lowerGradeEntry();
    highGradeEntry();
    return (0);
}