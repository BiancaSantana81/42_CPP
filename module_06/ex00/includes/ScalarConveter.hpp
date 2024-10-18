/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConveter.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:20:03 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/18 14:16:08 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVETER_HPP
#define SCALARCONVETER_HPP

#include <iostream>
#include <string>

#include "types.hpp"

class ScalarConveter
{
    private:

    // constructors

    ScalarConveter(void); // construtor padrão
    ScalarConveter(const ScalarConveter &other); // construtor de cópia
    ScalarConveter &operator=(const ScalarConveter &other); // atribuição por cópia
    ~ScalarConveter(void); // destrutor padrão

    public:

    /* method: convert a string in another type */
    static void convert(std::string input);
};

#endif