/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Electro.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:32:36 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/08 15:33:02 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELECTRO_HPP
#define ELECTRO_HPP

#include "../includes/AMateria.hpp"

class Electro : public AMateria
{
    public:

    // Constructors
    Electro(void);
    Electro(const Electro &other);
    Electro &operator=(const Electro &other);

    // Virtual functions
    AMateria *clone(void) const;
    void use(ICharacter &target);

    // Destrutor
    virtual ~Electro(void);
};

#endif