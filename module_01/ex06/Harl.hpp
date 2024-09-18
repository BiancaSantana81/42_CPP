/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:16:00 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/18 16:18:00 by bsantana         ###   ########.fr       */
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

enum logLevel
{
    DEBUG_LEVEL,
    INFO_LEVEL,
    WARNING_LEVEL,
    ERROR_LEVEL,
    INVALID_LEVEL
};

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

int convertEnum(std::string level);

#endif