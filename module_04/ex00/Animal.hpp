/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:33:31 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/01 14:23:37 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_GREEN  "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE   "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define RESET   "\033[0m"

class Animal
{
    protected:

    std::string _type;

    public:

    /*Constructors and Destructor*/
    Animal(void);
    Animal(std::string type);
    virtual ~Animal(void);
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    
    /* Getter and Setter */
    std::string getType() const;
    void setType(std:: string newType);
    
    /* function */
    virtual void makeSound() const;
};

#endif