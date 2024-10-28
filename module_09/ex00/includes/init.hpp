/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:30:19 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/28 12:33:15 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_HPP
#define INIT_HPP

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_YELLOW "\033[93m"
#define RESET   "\033[0m"


/* parsing input */
int parsing(int argc, char **argv);
int is_csv(const char *filename);

/* init program */
int runProgram(const std::string &filename);

#endif