/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:22:21 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/10 17:50:16 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <ctime>
#include <string>

class Bureaucrat
{
    private:

    const std::string _name;
    int         _grade;

    public:

    // Constructors 

    Bureaucrat(void); // construtor padrão 
    Bureaucrat(std::string name, int grade); // construtor padrão com inicialização de nome 
    ~Bureaucrat(void); // destrutor
    Bureaucrat(const Bureaucrat &other); // construtor de cópia
    Bureaucrat &operator=(const Bureaucrat &other); // atribuição por cópia

    // getters and setters
    std::string getName(void) const;
    int getGrade(void) const;
    void setGrade(int newGrade);

    //operadores de incremento e decremento para a nota do burocrata

    // Execptions

    class GradeTooHighException: public std::exception
    {
        public:
        virtual const char *message() const throw();
    };

    class GradeTooLowExeception: public std::exception
    {
        public:
        virtual const char *message()const throw();
    };
};

#endif