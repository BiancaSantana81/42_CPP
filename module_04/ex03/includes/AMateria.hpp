/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:58:07 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 14:07:19 by bsantana         ###   ########.fr       */
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

/* The AMateria class represents an abstract material in the game system. 
   As an abstract class, it defines the interface and behaviour that 
   all concrete materials must implement. 
   The class stores the type of the material (_type) and includes virtual methods 
   for cloning (clone) and use (use), which must be implemented by the 
   derived classes.
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