/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:30:19 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/11 10:43:57 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
#define PARSING_HPP

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

#include "BitcoinExchange.hpp"

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_YELLOW "\033[93m"
#define RESET   "\033[0m"

/* parsing input */
int parsing(int argc, char **argv);
int is_txt(const char *filename);

/* init program */
int runProgram(const std::string &filename);

/* utils */

void removeSpaces(std::string &line);
void validateDate(std::string date);
float validateValue(std::string value_str);
float stringToFloat(const std::string &valueStr);

#endif