/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:17:16 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/14 10:08:03 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

/* CONSTRUCTORS */

AForm::AForm(void): _name("standard form"), _gradeRequired(150), _gradeSign(1), _isSigned(false)
{
    std::cout << "AForm: " << _name << " ready for the bureaucrats!" << std::endl;
}

AForm::AForm(std::string name, int gradeRequired, int gradeSign):
    _name(name), _gradeRequired(gradeRequired), _gradeSign(gradeSign), _isSigned(false)
{
    if (_gradeRequired < 1 || _gradeSign < 1) {
        throw GradeTooHighException();
    }
    else if (_gradeRequired > 150 || _gradeSign > 150) {
        throw GradeTooLowException();
    }
    std::cout << "AForm: " << _name << " ready for the bureaucrats!" << std::endl;
}

AForm::AForm(const AForm &other) :
    _name(other._name), 
    _gradeRequired(other._gradeRequired), 
    _gradeSign(other._gradeSign), 
    _isSigned(other._isSigned)
{
    std::cout << "Copy constructor called." << std::endl;
}


AForm &AForm::operator=(const AForm &other)
{
    std::cout << "" << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;
    else
        std::cout << "Self-attribution detected! The objects already have the same address." << std::endl;
    return (*this);
}

/* GETTERS */

std::string AForm::getName(void) const
{
    return (_name);
}
int AForm::getGradeRequired(void) const
{
    return (_gradeRequired);
}

int AForm::getGradeSign(void) const
{
    return (_gradeSign);
}

bool AForm::getIsSigned(void) const
{
    return (_isSigned);
}

/* ERROR MESSAGES EXCEPTIONS */

const char* AForm::GradeTooHighException::what(void) const throw()
{
    return ("Error: The grade required to sign this Aform is too high! Only our top employee (grade 1) can handle this.");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
    return ("Error: The grade required to sign this Aform is too low! Interns only manage to reach grade 150.");
}

const char* AForm::AFormAlreadySignedException::what(void) const throw()
{
    return ("Error: The Aform has already been signed!");
}

/* METHODS */

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign) {
        throw GradeTooLowException();
    }
    if (_isSigned) {
        throw AFormAlreadySignedException();
    }
    _isSigned = true;
}

// overload operator AForm

std::ostream &operator<<(std::ostream &osStream, const AForm &that)
{
    osStream << BRIGHT_YELLOW "AForm_name: "  RESET << that.getName() 
             <<  BRIGHT_YELLOW ", grade_required: " RESET << that.getGradeRequired()
             <<  BRIGHT_YELLOW ", grade_sign: " RESET << that.getGradeSign()
             <<  BRIGHT_YELLOW ", signed: " RESET ;

    if (that.getIsSigned()) {
        osStream << "Yes.";
    } else {
        osStream << "No.";
    }

    return (osStream);
}

/* DESTRUCTOR */

AForm::~AForm(void)
{
    std::cout << "AForm: " << _name << " was destroyed in flames!" << std::endl;
}
