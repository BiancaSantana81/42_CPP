/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:39:06 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/14 15:33:19 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

/* Constructors */

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 5, 25),_target(target)
{
    std::cout  << "PresidentialPardonForm is available. Main target: "
    << _target << "." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) 
: AForm(other), _target(other._target)
{
    std::cout << "Copy constructor called." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
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

void        PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned()) {
        throw AFormAlreadySignedException();
    }
    if (executor.getGrade() > getGradeExec()) {
        throw GradeTooLowException();
    }
    std::cout << _target
              << " has been forgiven by the glorious Zaphod Beeblebrox!"
              << std::endl;
}

/* Destructor */

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout  << "PresidentialPardonForm with the target  objective: "
    << _target << " was destroyed in flames." << std::endl;
}