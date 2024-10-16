/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConveter.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:20:03 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/16 11:29:49 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVETER_HPP
#define SCALARCONVETER_HPP

#include <iostream>
#include <string>

class ScalarConveter
{
    private:

    public:

    // constructors

    ScalarConveter(void); // construtor padrão
    ScalarConveter(const ScalarConveter &other); // construtor de cópia
    ScalarConveter &operator=(const ScalarConveter &other); // atribuição por cópia
    ~ScalarConveter(void); // destrutor padrão

    /* method: convert a string in another type */
    static void convert(std::string input);
};

#endif