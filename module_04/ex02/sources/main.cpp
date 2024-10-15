/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:35 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/10 13:11:13 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main(void)
{
    /* Abstract class must return error */
    //AAnimal *wrong = new AAnimal();

    AAnimal *right = new Cat();

    right->makeSound();
    delete right;
    return (0);
}