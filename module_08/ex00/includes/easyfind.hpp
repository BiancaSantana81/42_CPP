/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:12:49 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/23 13:02:09 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_GREEN  "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE   "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN   "\033[96m"
#define BRIGHT_WHITE  "\033[97m"
#define RESET   "\033[0m"

// container libraries

#include <vector>
#include <deque>
#include <list>

// template implementation

template <typename T>
typename T::iterator easyfind(T &container, int number);

// extras: point to start and end of container

template <typename T, size_t N>
T *begin(T (&container)[N]);

template <typename T, size_t N>
T *end(T (&container)[N]);

template <typename T>
void printContainer(const T& container);

#include "easyfind.tpp"

#endif