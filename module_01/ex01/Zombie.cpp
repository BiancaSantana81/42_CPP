#include "Zombie.hpp"

/* Constructor and Destructor */

Zombie::Zombie(void)
{
    std::cout << "Zombie born." << std::endl;
}

Zombie::~Zombie( void )
{
    std::cout << _name << " died!" << std::endl;
}

/* Zombie class functions */

void Zombie::announce(void)
{
    std:: cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/* Getters and setters */

std::string Zombie::getName(void) const
{
    return (this->_name);
}

void Zombie::setName(const std::string &newName)
{
    this->_name = newName;
}
