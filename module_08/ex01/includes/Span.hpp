/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:45:03 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/23 17:52:45 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_CPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <iterator>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// colors

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_GREEN  "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE   "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN   "\033[96m"
#define BRIGHT_WHITE  "\033[97m"
#define RESET   "\033[0m"

class Span
{
    private:
    
    unsigned int    _maxSize;
    std::vector<int> _numbers;

    public:

    // constructors
    
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);

    // methods

    void addNumber(const int number);
    int shortestSpan(void);
    int longestSpan(void);

    // extra: filling containers

    void fillContainer(int values[], size_t size);

    // destructor
    ~Span(void);
    
};

// virtualize what to customize error messages for executions

class SpanFullException : public std::exception
{
    public:
    
    virtual const char *what() const throw ();
};

class NotEnoughNumbersException : public std::exception
{
    public:
    
    virtual const char *what() const throw ();
};

#endif