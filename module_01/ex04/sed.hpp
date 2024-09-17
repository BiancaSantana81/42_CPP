/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:21:41 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 18:36:20 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#define RED     "\033[31m"
#define RESET   "\033[0m"

#include <iostream>
#include <fstream>
#include <string>

bool processInput(int argc, char **argv, std::ifstream &input, std::ofstream &output, std::string &s1, std::string &s2);
void replace(std::ifstream &input, std::ofstream &output, const std::string &s1, const std::string &s2);

#endif