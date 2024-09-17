/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:04 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 10:51:03 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define RED  "\033[31m"
#define RESET "\033[0m"

#include <iostream>

class Zombie
{
    private:

    std::string _name;

    public:

    Zombie(void);
    ~Zombie(void);

    void announce(void);

    std::string getName(void) const;
    void setName(const std::string &newName);
};

Zombie* zombieHorde(int N, std::string name);

#endif