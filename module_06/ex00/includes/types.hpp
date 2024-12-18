/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:01:43 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/18 17:26:34 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_HPP
#define TYPES_HPP

#include "ScalarConveter.hpp"
#include <sstream>
#include <limits>

enum ECases
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_LITERAL,
    MEGA_IMPOSSIBLE
};

ECases detectType(const std::string &input);
void   convertType(ECases type, std::string input);

#endif