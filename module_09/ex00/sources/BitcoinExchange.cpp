/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:41:19 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/28 17:51:47 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/* CONSTRUCTORS */

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _data = other._data;
    }
    return (*this);
}

// METHODS

void BitcoinExchange::populatingContainer(std::ifstream &file)
{
    std::string line;

    std::getline(file, line);
    removeSpaces(line);
    if (line != "date | value")
            throw std::runtime_error("Invalid header! Insert: date | value");
    while (std::getline(file, line))
    {   
        if (line.empty())
        continue ;
        formatData(line);
    }
}

void BitcoinExchange::formatData(std::string line)
{
    removeSpaces(line);
    size_t separator_pos = line.find_first_of("|");
    if (separator_pos == std::string::npos)
        throw std::runtime_error("Invalid line format: " + line);

    std::string date = line.substr(0, separator_pos);
    std::string value_str = line.substr(separator_pos + 1);

    removeSpaces(date);
    removeSpaces(value_str);

    validateDate(date);
    float value = validateValue(value_str);
    
    _data[date] = value; // inserindo valores com base em chave valor no contêiner _data
}

void BitcoinExchange::printData() const
{
    for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}

/* DESTRUCTOR */

BitcoinExchange::~BitcoinExchange() {}
