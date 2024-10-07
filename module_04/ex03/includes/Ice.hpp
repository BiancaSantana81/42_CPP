/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:32:40 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 15:53:49 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

/* A classe Ice é uma implementação concreta da classe abstrata AMateria, representando um 
   material do tipo gelo (Ice). Ela define métodos polimórficos, incluindo as funções 
   clone e use, que especificam o comportamento único da matéria de gelo. O método clone 
   permite a criação de uma cópia da instância de Ice, enquanto o método use define como 
   a matéria de gelo interage com um alvo do tipo ICharacter. 
*/

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
    
    // Constructors
    Ice(void);
    Ice(const Ice &other);
    Ice &operator=(const Ice &other);

    
    // Virtual functions
    AMateria *clone(void) const;
    void use(ICharacter &target);

    // Destrutor
    virtual ~Ice(void);
};

#endif