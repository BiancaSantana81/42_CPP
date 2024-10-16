/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:01:11 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/18 10:38:18 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <ctime> // for time ()
#include <cstdlib> // for rand() and srand()
#include <stdexcept> 

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif