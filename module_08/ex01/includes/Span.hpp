/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:45:03 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/23 16:54:04 by bsantana         ###   ########.fr       */
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

    //void fillContainer();

    // destructor
    ~Span(void);
    
};

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