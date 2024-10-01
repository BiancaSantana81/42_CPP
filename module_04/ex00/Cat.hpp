/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:15:01 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/01 15:05:38 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"

class Cat: public Animal
{
    public:

    Cat(void);
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    virtual ~Cat(void);

    virtual void makeSound() const;
};

#endif
