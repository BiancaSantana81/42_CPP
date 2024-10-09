/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:08:32 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 17:12:10 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tests.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

void arrayAnimals(void)
{
    Animal *animals[6];

    for (int i = 0; i < 6; i++)
    {
        if (i % 2 == 0)
        {
            animals[i] = new Dog();
            animals[i]->makeSound();
        }
        else
        {
            animals[i] = new Cat();
            animals[i]->makeSound();
        
        }
    }
    for (int i = 0; i < 6; i++)
        delete animals[i];
}

void showCatIdeas()
{
    Animal *animal;

    animal = new Cat();
    animal->makeSound();
    if (Cat* cat = dynamic_cast<Cat*>(animal))
        cat->printIdeas();
    delete animal;
}

void showDogIdeas()
{
    Animal *animal;

    animal = new Dog();
    animal->makeSound();
    if (Dog* dog = dynamic_cast<Dog*>(animal))
        dog->printIdeas();
    delete animal;
}

void deepCopy(void)
{
    Dog basic;
    {
        Dog tmp = basic;
        tmp.printIdeas();
    }
}