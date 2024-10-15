/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:22:21 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/15 09:43:09 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_CYAN   "\033[96m"
#define BRIGHT_RED    "\033[91m"
#define RESET   "\033[0m"

#include <iostream>
#include <ctime>
#include <string>

class AForm;

class Bureaucrat
{
    private:

    const std::string _name;
    int         _grade;

    public:

    // constructors 

    Bureaucrat(void);
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat(void);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);

    // getters
    std::string getName(void) const;
    int getGrade(void) const;

    // up or down the grade
    void upGrade(void);
    void downGrade(void);

    /* check that the form has been signed by the bureaucrat */
    void signForm(AForm &form) const;

    /* new method: checks that the bureaucrat has executed the orders on a form */
    void executeForm(AForm const & form);

    // execeptions

    class GradeTooHighException: public std::exception
    {
        public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        public:
        virtual const char *what()const throw();
    };
};

std::ostream &operator<<(std::ostream &osStream, Bureaucrat const &that);

#endif