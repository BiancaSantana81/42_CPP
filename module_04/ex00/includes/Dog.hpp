/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:14:25 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/01 17:25:13 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"

class Dog: public Animal
{
    public:

    Dog(void);
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    virtual ~Dog(void);

    void makeSound() const;
};

#endif
