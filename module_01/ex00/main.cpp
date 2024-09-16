/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:54:05 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/16 15:54:33 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
   Zombie zombie;
   std::string name_zombie;

   name_zombie = "Foo";

   zombie.setName(name_zombie);

}