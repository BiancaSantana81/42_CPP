/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:22:21 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/11 13:33:53 by bsantana         ###   ########.fr       */
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

class Bureaucrat
{
    private:

    const std::string _name;
    int         _grade;

    public:

    // constructors 

    Bureaucrat(void); // construtor padrão 
    Bureaucrat(std::string name, int grade); // construtor padrão com inicialização de nome 
    ~Bureaucrat(void); // destrutor
    Bureaucrat(const Bureaucrat &other); // construtor de cópia
    Bureaucrat &operator=(const Bureaucrat &other); // atribuição por cópia

    // getters
    std::string getName(void) const;
    int getGrade(void) const;

    // up or down the grade
    void upGrade(void);
    void downGrade(void);

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