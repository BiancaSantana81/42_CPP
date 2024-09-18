/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:20:19 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/18 16:09:26 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

/* Libraries */

#include <iostream>
#include <string>

/* Class */

class Harl
{
    private:

    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    public:

    void complain(std:: string level);
    Harl();
    ~Harl();
};

#endif