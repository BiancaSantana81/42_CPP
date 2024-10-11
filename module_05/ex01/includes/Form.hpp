/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:17:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/11 14:39:44 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_CYAN   "\033[96m"
#define BRIGHT_RED    "\033[91m"
#define RESET   "\033[0m"

class Bureaucrat;

class Form
{
    private:

    const std::string _name;
    const int        _gradeRequired;
    const int        _gradeSign;
    bool             _isSigned;

    public:

    // constructors

    Form(void);
    Form(std::string &name, int gradeRequired, int gradeSign);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form(void);

    // getters

    std::string getName(void) const;
    int         getGradeRequired(void) const;
    int         getGradeSign(void) const;
    bool        getIsSigned(void) const;

    // exceptions

    class GradeTooHighException : public std::exception
    {
        public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
        virtual const char *what() const throw();
    };

    // method
    
    void        beSigned(const Bureaucrat &bureaucrat);
    
};

// overload operator Form

std::ostream &operator<<(std::ostream &osStream, Form const &that);

#endif