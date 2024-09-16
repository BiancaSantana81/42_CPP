/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:54:05 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/16 17:51:10 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
   Zombie *zombie;

   zombie = newZombie("Maria");
   zombie->announce();
   delete zombie;

   randomChump("Joana");
   return (0);
}
