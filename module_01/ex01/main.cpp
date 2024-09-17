/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:48:40 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 11:15:21 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    int N;
    
    /* Teste with zero zombies */
    std::cout << RED "Test with zero zombies." RESET << std::endl;
    N = 0;
    Zombie *horde1 = zombieHorde(N, "No zombies");
    if (horde1 == NULL)
        std::cout << "Empty array: Returns pointer to NULL.\n";
   
    /* Teste with five zombies */
    std::cout << RED "Test with five zombies." RESET << std::endl;
    N = 5;
    Zombie *horde2 = zombieHorde(N, "Five guys");
    for (int i = 0; i < N; i++)
        horde2->announce();
    /* Checking return for the first zombie in the horder2 array */
    if (horde2 != NULL)
    {
        std::cout << "Address horde2: " << horde2 << std::endl;
        std::cout << "Address horde2[0] : " << &horde2[0] << std::endl;
    }
    delete[] horde2;
    return (0);
}
