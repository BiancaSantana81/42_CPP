/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConveter.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:20:03 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/21 10:03:06 by bsantana         ###   ########.fr       */
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

    ScalarConveter(void);
    ScalarConveter(const ScalarConveter &other);
    ScalarConveter &operator=(const ScalarConveter &other);
    ~ScalarConveter(void);

    public:

    /* method: convert a string in another type */
    static void convert(std::string input);
};

#endif