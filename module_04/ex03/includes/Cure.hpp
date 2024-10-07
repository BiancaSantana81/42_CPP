/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:33:01 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 11:22:14 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

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