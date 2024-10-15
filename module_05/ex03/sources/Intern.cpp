/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:51:17 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/15 11:13:07 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

/* CONSTRUCTORS */

Intern::Intern(void)
{
    std::cout << "An intern is ready to create forms!" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy constructor called." << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return (*this);
}

/* Method: just make forms */

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
    std::string current_level[3] = {"presidential pardon", "robotomy request", "shubbery creation"};
    
    int i;
    for (i = 0; i < 4; i++)
    {
        if (formName == current_level[i])
            break ;
    }
    switch (i)
    {
    case 0:
        return new PresidentialPardonForm (target);
    case 1:
        return new RobotomyRequestForm(target);
    case 2:
        return new ShrubberyCreationForm (target);
    default:
        std::cout << BRIGHT_RED "Error: I don't know the: " << formName << " form template." RESET << std::endl;
        return (NULL);
    }
}

/* DESTRUCTOR */

Intern::~Intern(void)
{
     std::cout << "The intern is now free!" << std::endl;
}

