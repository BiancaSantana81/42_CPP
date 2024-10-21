/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:01:11 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/21 11:05:34 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <ctime> 
#include <cstdlib>
#include <stdexcept> 

/* 
   O polimorfismo ocorre em tempo de execução, permitindo que uma interface comum 
   (como um ponteiro ou referência para a classe base) manipule objetos de diferentes 
   classes derivadas.

   Ao declarar objetos como ponteiros ou referências para a classe base, o compilador 
   sabe apenas que eles pertencem à hierarquia da classe base. No entanto, a identificação 
   do tipo específico da classe derivada ocorre somente em tempo de execução.

   O uso de dynamic_cast permite converter de forma segura um ponteiro ou referência 
   da classe base para um tipo derivado durante a execução. Se a conversão falhar, 
   dynamic_cast retorna um ponteiro nulo (para ponteiros) ou lança uma exceção  std::exception 
   (para referências).

   No contexto da função identify, usamos dynamic_cast para identificar o tipo real 
   do objeto apontado por um ponteiro ou referência para a classe base (durante a execução).
*/

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif