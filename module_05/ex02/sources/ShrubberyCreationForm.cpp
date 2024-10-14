/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:54:48 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/14 11:58:35 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

/* Constructors */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 72, 45),_target(target)
{
    std::cout  << "ShrubberyCreationForm is available. Main target: "
    << _target << "." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
: AForm(other), _target(other._target)
{
    std::cout << "Copy constructor called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    else
         std::cout << "Self-attribution detected! The objects already have the same address." << std::endl;
    return (*this);
}

/* Method - execute form */

void        ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned()) {
        throw AFormAlreadySignedException();
    }
    if (executor.getGrade() > getGradeExec()) {
        throw GradeTooLowException();
    }
    // criar lógica própria para este método
}

/* Destructor */

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout  << "ShrubberyCreationForm with the target  objective: "
    << _target << " was destroyed in flames." << std::endl;
}
