/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:17:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/14 11:23:23 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_CYAN   "\033[96m"
#define BRIGHT_RED    "\033[91m"
#define RESET   "\033[0m"

class Bureaucrat;

class AForm
{
    private:

    const std::string _name;
    const int        _gradeExec;
    const int        _gradeSign;
    bool             _isSigned;

    public:

    // constructors

    AForm(void);
    AForm(std::string name, int gradeExec, int gradeSign);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm(void);

    // getters

    std::string getName(void) const;
    int         getGradeExec(void) const;
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

    class AFormAlreadySignedException : public std::exception
    {
        public:
        virtual const char *what() const throw();
    };

    // methods
    
    void                beSigned(const Bureaucrat &bureaucrat);
    virtual void        execute(Bureaucrat const & executor) const = 0;
};

// overload operator AForm

std::ostream &operator<<(std::ostream &osStream, AForm const &that);

#endif