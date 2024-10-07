/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:58:07 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 12:46:09 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

/* BRIGHT COLORS */
#define BRIGHT_RED    "\033[91m"
#define RESET   "\033[0m"

class ICharacter;

class AMateria
{
    protected:
    
    std::string _type;

    public:
    
    // Construtores
    AMateria(void); // Constructor sem atribuir type na inicialização;
    AMateria(std::string const &type); // Construtor com tipo de matéria
    AMateria(const AMateria &other); // Construtor de cópia
    AMateria &operator=(const AMateria &other); // Operador de atribuição por cópia
    
    //Getter and Setter
    std::string const &getType() const;
    void setType(std::string newType);

    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
    
    // Destrutor
    virtual ~AMateria(void);
};

#endif