/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:22:25 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/11 12:00:40 by bsantana         ###   ########.fr       */
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

/* ERROR MESSAGES */

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("The highest possible grade is 1!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("The lowest possible grade is 150!");
}

/* Ao sobrecarregar o operador '<<' para a classe Bureaucrat, permitimos que o objeto 'burocrata' seja impresso diretamente com 'std::cout << burocrata'.
   Isso exibe o nome e o grau do Bureaucrat conforme implementado na função de sobrecarga.
*/

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
