/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:17:16 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/14 11:27:08 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

/* CONSTRUCTORS */

Form::Form(void): _name("standard form"), _gradeExec(150), _gradeSign(1), _isSigned(false)
{
    std::cout << "Form: " << _name << " ready for the bureaucrats!" << std::endl;
}

Form::Form(std::string name, int gradeExec, int gradeSign):
    _name(name), _gradeExec(gradeExec), _gradeSign(gradeSign), _isSigned(false)
{
    if (_gradeExec < 1 || _gradeSign < 1) {
        throw GradeTooHighException();
    }
    else if (_gradeExec > 150 || _gradeSign > 150) {
        throw GradeTooLowException();
    }
    std::cout << "Form: " << _name << " ready for the bureaucrats!" << std::endl;
}

Form::Form(const Form &other) :
    _name(other._name), 
    _gradeExec(other._gradeExec), 
    _gradeSign(other._gradeSign), 
    _isSigned(other._isSigned)
{
    std::cout << "Copy constructor called." << std::endl;
}


Form &Form::operator=(const Form &other)
{
    std::cout << "" << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;
    else
        std::cout << "Self-attribution detected! The objects already have the same address." << std::endl;
    return (*this);
}

/* GETTERS */

std::string Form::getName(void) const
{
    return (_name);
}
int Form::getGradeExec(void) const
{
    return (_gradeExec);
}

int Form::getGradeSign(void) const
{
    return (_gradeSign);
}

bool Form::getIsSigned(void) const
{
    return (_isSigned);
}

/* ERROR MESSAGES EXCEPTIONS */

const char* Form::GradeTooHighException::what(void) const throw()
{
    return ("Error: The grade grade exec to sign this form is too high! Only our top employee (grade 1) can handle this.");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
    return ("Error: The grade grade exec to sign this form is too low! Interns only manage to reach grade 150.");
}

const char* Form::FormAlreadySignedException::what(void) const throw()
{
    return ("Error: The form has already been signed!");
}

/* METHODS */

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSign) {
        throw GradeTooLowException();
    }
    if (_isSigned) {
        throw FormAlreadySignedException();
    }
    _isSigned = true;
}

// overload operator Form

std::ostream &operator<<(std::ostream &osStream, const Form &that)
{
    osStream << BRIGHT_YELLOW "Form_name: "  RESET << that.getName() 
             <<  BRIGHT_YELLOW ", grade_exec: " RESET << that.getGradeExec()
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

Form::~Form(void)
{
    std::cout << "Form: " << _name << " was destroyed in flames!" << std::endl;
}
