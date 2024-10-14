/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:33:26 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/14 11:53:07 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

/* Constructors */

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45),_target(target)
{
    std::cout  << "RobotomyRequestForm is available. Main target: "
    << _target << "." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) 
: AForm(other), _target(other._target)
{
    std::cout << "Copy constructor called." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
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

void        RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned()) {
        throw AFormAlreadySignedException();
    }
    if (executor.getGrade() > getGradeExec()) {
        throw GradeTooLowException();
    }

    std::cout << "tec tec tec..." << std::endl;
    srand(time(NULL)); // chamar dentro do main???

    if (std::rand() % 2 == 0)
         std::cout << _target << " has been successfully robotomized!" << std::endl;
    else
        std::cout << "The robotomy of " << _target << " failed miserably." << std::endl;
}

/* Destructor */

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout  << "RobotomyRequestForm with the target  objective: "
    << _target << " was destroyed in flames." << std::endl;
}
