/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:04 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/16 17:50:07 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

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

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif