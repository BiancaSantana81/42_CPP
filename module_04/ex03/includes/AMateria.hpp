/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:58:07 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 15:50:01 by bsantana         ###   ########.fr       */
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

/* A classe AMateria representa uma matéria abstrata no sistema de jogo. 
   Como uma classe abstrata, ela define a interface e o comportamento que 
   todas as matérias concretas devem implementar. 
   A classe armazena o tipo da matéria (_type) e inclui métodos virtuais 
   para clonagem (clone) e uso (use), que devem ser implementados pelas 
   classes derivadas.
*/

class AMateria
{
    protected:
    
    std::string _type;

    public:
    
    // Construtores
    AMateria(void);
    AMateria(std::string const &type);
    AMateria(const AMateria &other);
    AMateria &operator=(const AMateria &other);
    
    //Getter and Setter
    std::string const &getType() const;
    void setType(std::string newType);

    // Virtual functions
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
    
    // Destrutor
    virtual ~AMateria(void);
};

#endif