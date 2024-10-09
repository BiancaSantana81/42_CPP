/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:32:40 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 14:06:32 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

/* The Ice class is a concrete implementation of the AMateria abstract class, representing an 
   material (Ice). It defines polymorphic methods, including the 
   clone and use functions, which specify the unique behaviour of the ice material. The clone 
   method allows the creation of a copy of the Ice instance, while the use method defines how 
   the ice matter interacts with a target of type ICharacter. 
*/

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
    
    // Constructors
    Ice(void);
    Ice(const Ice &other);
    Ice &operator=(const Ice &other);

    
    // Virtual functions
    AMateria *clone(void) const;
    void use(ICharacter &target);

    // Destrutor
    virtual ~Ice(void);
};

#endif