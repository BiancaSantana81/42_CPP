/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Future.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:19:59 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/08 15:23:42 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUTURE_HPP
#define FUTURE_HPP

#include "../includes/AMateria.hpp"

class Future : public AMateria
{
    public:

    // Constructors
    Future(void);
    Future(const Future &other);
    Future &operator=(const Future &other);

    // Virtual functions
    AMateria *clone(void) const;
    void use(ICharacter &target);

    // Destrutor
    virtual ~Future(void);
};

#endif