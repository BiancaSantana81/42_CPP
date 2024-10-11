/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:17:16 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/11 14:44:49 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

/* CONSTRUCTORS */

Form::Form(void): _name("standard form"), _gradeRequired(150), _gradeSign(1), _isSigned(false)
{
    std::cout << "Form: " << _name << " ready for the bureaucrats!" << std::endl;
}

Form::Form(std::string &name, int gradeRequired, int gradeSign):
    _name(name), _gradeRequired(gradeRequired), _gradeSign(gradeSign), _isSigned(false)
{
    if (_gradeRequired < 1 || _gradeSign < 1) {
        throw GradeTooHighException();
    }
    else if (_gradeRequired > 150 || _gradeSign > 150) {
        throw GradeTooLowException();
    }
    std::cout << "Form: " << _name << " ready for the bureaucrats!" << std::endl;
}

Form::Form(const Form &other) :
    _name(other._name), 
    _gradeRequired(other._gradeRequired), 
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
int Form::getGradeRequired(void) const
{
    return (_gradeRequired);
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
    return ("This grade is too high! Our best employee is level 1.");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
    return ("This level is too low! Our intern is at level 150.");
}

/* METHOD */


// overload operator Form

std::ostream &operator<<(std::ostream &osStream, const Form &that)
{
    osStream << BRIGHT_YELLOW "Form_name: "  RESET << that.getName() 
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

Form::~Form(void)
{
    std::cout << "Form: " << _name << " was destroyed in flames!" << std::endl;
}
