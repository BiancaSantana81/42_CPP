/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:22:25 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/10 18:13:45 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

/* CONSTRUCTORS */

Bureaucrat::Bureaucrat(void): _name("random annoying"), _grade(150)
{
    std::cout << _name << " is ready to be bureaucratic!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    std::cout << _name << " is ready to be bureaucratic!" << std::endl;
    if (grade < 1)
        throw GradeTooLowExeception();
    else if (grade > 150)
        throw GradeTooHighExeception();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Bureaucratic copy constructor called." << std::endl;
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other)
        _grade = other._grade;
    else
         std::cout << "Self-attribution detected! The objects already have the same address." <<std::endl;
    return (*this);
}

/* GETTER NAME */

std::string Bureaucrat::getName(void) const
{
    return (_name);
}

/* GETTER AND SETTER GRADE */

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void Bureaucrat::setGrade(int newGrade)
{
    _grade = newGrade;
}

/* INCREMENT AND DECREMENT */

/* ERROR MESSAGES */

const char *Bureaucrat::GradeTooHighExeception::message(void) const throw()
{
    return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowExeception::message(void) const throw()
{
    return ("Grade is too low!");
}

/* DESTRUCTORS */

Bureaucrat::~Bureaucrat(void)
{
    std::cout << _name << " died of boredom!" << std::endl;
}
