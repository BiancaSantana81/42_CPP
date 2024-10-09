/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:44:46 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 14:46:47 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

static void soundsAnimals(void);
static void catSounds(void);
static void dogSounds(void);
static void wrongAnimalSounds(void);
static void wrongCatSounds(void);

int main(void)
{
    std::cout << BRIGHT_BLUE "******** unknown animal ************" RESET << std::endl;
    soundsAnimals();
    std::cout << BRIGHT_BLUE "********** cat tests   *************" RESET << std::endl;
    catSounds();
    std::cout << BRIGHT_BLUE "********** dog tests ***************" RESET << std::endl;
    dogSounds();
    std::cout << BRIGHT_BLUE "******* wrong animal tests  **********" RESET << std::endl;
    wrongAnimalSounds();
    std::cout << BRIGHT_BLUE "******* wrong wrong cat tests *******" RESET << std::endl;
    wrongCatSounds();
    return (0);
}

static void soundsAnimals(void)
{
    const Animal *unknown;

    unknown = new Animal();
    std::cout << "Type: " << unknown->getType() << std::endl;
    unknown->makeSound();
    delete unknown;
}

static void catSounds(void)
{
    const Animal *cat;

    cat = new Cat();
    std::cout << "Type: " << cat->getType() << std::endl;
    cat->makeSound();
    delete cat;
}

static void dogSounds(void)
{
    const Animal *dog;

    dog = new Dog();
    std::cout << "Type: " << dog->getType() << std::endl;
    dog->makeSound();
    delete dog;
}

static void wrongAnimalSounds(void)
{
    const WrongAnimal *weird;
    
    weird = new WrongAnimal();
    std::cout << "Type: " << weird->getType() << std::endl;
    weird->makeSound();
    delete weird;
}

static void wrongCatSounds(void)
{
    const WrongAnimal *wrongCat;

    wrongCat = new WrongCat();
    std::cout << "Type: " << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    delete wrongCat;
}
