/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:01:11 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/21 11:17:25 by bsantana         ###   ########.fr       */
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
   Polymorphism occurs at runtime, allowing a common interface 
   (such as a pointer or reference to the base class) to manipulate objects of different 
   derived classes.

   When declaring objects as pointers or references to the base class, the compiler 
   only knows that they belong to the base class hierarchy. However, identifying 
   the specific type of the derived class only occurs at runtime.

   The use of dynamic_cast makes it possible to safely convert a pointer or reference 
   from the base class to a derived type during execution. If the conversion fails, 
   dynamic_cast returns a null pointer (for pointers) or throws a std::exception 
   exception (for references).

   In the context of the identify function, we use dynamic_cast to identify the actual type 
   of the object pointed to by a pointer or reference to the base class (during execution).
*/

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif