/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:22:25 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/15 09:40:01 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

/* CONSTRUCTORS */

Bureaucrat::Bureaucrat(void): _name("random annoying"), _grade(150)
{
    std::cout << _name << " is ready to be bureaucratic!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    if (grade < 1) {
        throw GradeTooHighException();
    }
    else if (grade > 150) {
        throw GradeTooLowException();
    }
    std::cout << _name << " is ready to be bureaucratic!" << std::endl;
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

/* GETTERS */

std::string Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

/* INCREMENT AND DECREMENT */

void Bureaucrat::upGrade(void)
{
    if (_grade == 1) {
        throw GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::downGrade(void)
{
    if (_grade == 150) {
        throw GradeTooLowException();
    }
    _grade++;
}

/* Method: check that the bureaucrat has signed the form */

void Bureaucrat::signForm(AForm &form) const
{
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << "." << std::endl;
    } catch (const std::exception &e) {
        std::cout << _name << BRIGHT_RED " could not sign " RESET << form.getName() 
                  << " why " << e.what() << std::endl;
    }
}

/* Method: get the bureaucrat to execute the form (if possible) */

void Bureaucrat::executeForm(AForm const &form)
{
    try {
        form.execute(*this);
        std::cout << _name << "  executed the form: " << form.getName() << "." << std::endl;
    } catch (const std::exception &e) {
        std::cout << BRIGHT_RED << _name << " could not execute "<< form.getName() 
                  << " why " << e.what() << RESET << std::endl;
    }
}

/* ERROR MESSAGES EXCEPTIONS */

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("The highest possible grade is 1!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("The lowest possible grade is 150!");
}

/* overload operator for bureaucrat */

std::ostream &operator<<(std::ostream &osStream, Bureaucrat const &that)
{
    osStream << that.getName() << ", bureaucrat grade " << that.getGrade() << ".";
    return(osStream);
}

/* DESTRUCTORS */

Bureaucrat::~Bureaucrat(void)
{
    std::cout << _name << " died of boredom!" << std::endl;
}
