/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:15:13 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/11 17:58:13 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.hpp"

static bool isValidDay(ssize_t day, ssize_t month, ssize_t year);
static bool isLeapYear(ssize_t year);
static bool isValidMonth(ssize_t month);

void removeSpaces(std::string &line)
{
    size_t start = line.find_first_not_of(" \t");
    size_t end = line.find_last_not_of(" \t");
    
    if (start != std::string::npos && end != std::string::npos)
        line = line.substr(start, end - start + 1);
    else if (start != std::string::npos)
        line = line.substr(start);
    else if (end != std::string::npos)
        line = line.substr(0, end + 1);
}

void validateDate(std::string date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        throw std::runtime_error("Invalid date format: " + date);
    }

    std::string year_str = date.substr(0, 4);
    std::string month_str = date.substr(5, 2);
    std::string day_str = date.substr(8, 2);

    ssize_t year = 0, month = 0, day = 0;
    std::istringstream iss;

    iss.str(year_str);
    if (!(iss >> year) || year < 1)
        throw std::runtime_error("Invalid year: " + date);

    iss.clear();

    iss.str(month_str);
    if (!(iss >> month) || !isValidMonth(month))
        throw std::runtime_error("Invalid month: " + date);

    iss.clear();

    iss.str(day_str);
    if (!(iss >> day) || !isValidDay(day, month, year))
        throw std::runtime_error("Invalid day: " + date);
}

float validateValue(std::string value_str)
{
    float value;
    std::istringstream iss(value_str);
    
    if (!(iss >> value) || !iss.eof())
        throw std::runtime_error("invalid");
    if (value < 0)
        throw std::runtime_error("negative");
    if (value > 1000)
        throw std::runtime_error("too large");
    return (value);
}

float stringToFloat(const std::string &valueStr)
{
    std::istringstream iss(valueStr);
    float value;

    iss >> value;
    if (iss.fail()) {
        throw std::runtime_error("Invalid float value: " + valueStr);
    }
    return (value);
}

static bool isValidMonth(ssize_t month)
{
    return month >= 1 && month <= 12;
}

static bool isLeapYear(ssize_t year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

static bool isValidDay(ssize_t day, ssize_t month, ssize_t year)
{
    if (day < 1 || day > 31)
        return (false);

    if (month == 4 || month == 6 || month == 9 || month == 11)
        return (day <= 30);
    if (month == 2)
        return (day <= (isLeapYear(year) ? 29 : 28));
    return (day <= 31);
}
