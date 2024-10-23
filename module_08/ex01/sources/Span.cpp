/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:45:07 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/23 16:55:04 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

/* CONSTRUCTORS */

Span::Span(unsigned int N): _maxSize(N), _numbers() {};

Span::Span(const Span &other) 
    : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return (*this);
}

/* METHODS */

void Span::addNumber(const int number)
{
    if (_numbers.size() >= _maxSize) {
        throw SpanFullException();
    }
    _numbers.push_back(number);
}

int Span::shortestSpan(void)
{
    if (_numbers.size() < 2) {
        throw NotEnoughNumbersException();
    }

    std::vector<int> sortedNumber = _numbers;
    std::sort(sortedNumber.begin(), sortedNumber.end());
    
    int minSpan = INT_MAX;
    for (int i = 1; i < sortedNumber[i]; i++)
    {
        int diff = sortedNumber[i] - sortedNumber[i - 1];
        minSpan = std::min(minSpan, diff);
    }
    return (minSpan);
}

int Span::longestSpan(void)
{
    if (_numbers.size() < 2) {
        throw NotEnoughNumbersException();
    }
    
    int minValue = *std::min_element(_numbers.begin(), _numbers.end());
    int maxValue = *std::max_element(_numbers.begin(), _numbers.end());

    return (maxValue - minValue);
}

/* extra: */
//void Span::fillContainer();

/* personalized error messages for executions */

const char *SpanFullException::what() const throw()
{
    return ("The container is already full!");
}

const char *NotEnoughNumbersException::what() const throw()
{
    return ("Not enough numbers to calculate a span!");
}

/* DESTRUCTOR */

Span::~Span(void) {}