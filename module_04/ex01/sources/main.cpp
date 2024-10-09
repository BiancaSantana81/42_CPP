/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:35 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 17:12:42 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/tests.hpp"

int main(void)
{
    Dog basic;
    {
        Dog tmp = basic;
        tmp.printIdeas();
    }
    std::cout << BRIGHT_MAGENTA "***************** ARRAY TESTS *****************" RESET << std::endl;
    arrayAnimals();
    std::cout << BRIGHT_MAGENTA "***************** CAT IDEAS TESTS *****************" RESET << std::endl;
    showCatIdeas();
    std::cout << BRIGHT_MAGENTA "***************** DOG IDEAS TESTS *****************" RESET << std::endl;
    showDogIdeas();
    std::cout << BRIGHT_MAGENTA "***************** DEEP COPY TESTS *****************" RESET << std::endl;
    deepCopy();
}
