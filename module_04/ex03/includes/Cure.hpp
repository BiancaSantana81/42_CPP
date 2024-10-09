/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:33:01 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 14:06:47 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

/* The Cure class is a concrete implementation of the AMateria abstract class, representing a 
   material of type Cure. It defines polymorphic methods, including the 
   clone and use functions, which specify the unique behaviour of the cure material. The clone 
   method allows you to create a copy of the Cure instance, while the use method defines how 
   the healing matter interacts with a target of the ICharacter type, allowing the character to 
   to heal its wounds and recover health.
*/

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
    
    // Constructors
    Cure(void);
    Cure(const Cure &other);
    Cure &operator=(const Cure &other);

    // Virtual functions
    AMateria *clone(void) const;
    void use(ICharacter &target);

    // Destrutor
    virtual ~Cure(void);
};

#endif