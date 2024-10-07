/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:33:01 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 15:53:43 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

/* A classe Cure é uma implementação concreta da classe abstrata AMateria, representando um 
   material do tipo cura (Cure). Ela define métodos polimórficos, incluindo as funções 
   clone e use, que especificam o comportamento único da matéria de cura. O método clone 
   permite a criação de uma cópia da instância de Cure, enquanto o método use define como 
   a matéria de cura interage com um alvo do tipo ICharacter, permitindo que o personagem 
   cure suas feridas e recupere saúde.
*/

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
    
    // Constructors
    Cure(void);
    Cure(const Cure &other);
    Cure &operator=(const Cure &other);

    
    // Virtual functions
    AMateria *clone(void) const;
    void use(ICharacter &target);

    // Destrutor
    virtual ~Cure(void);
};

#endif