/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:41:19 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/29 18:16:04 by bsantana         ###   ########.fr       */
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

void BitcoinExchange::loadingData(std::ifstream &file)
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
    std::string valueStr = line.substr(separator_pos + 1);

    removeSpaces(date);
    removeSpaces(valueStr);

    validateDate(date);
    float value = validateValue(valueStr);
    (void)value; // para de utlizar assim
}


float stringToFloat(const std::string &valueStr) {
    std::istringstream iss(valueStr);
    float value;
    iss >> value;
    if (iss.fail()) {
        throw std::runtime_error("Invalid float value: " + valueStr);
    }
    return value;
}

int BitcoinExchange::populatingContainer(std::string csv)
{
    std::ifstream file(csv.c_str());

    if (!file) {
        throw std::runtime_error("Error opening file! Try again with a valid data.csv.");
    }

    std::string line;
    std::getline(file, line);
    removeSpaces(line);
    if (line != "date,exchange_rate") {
        throw std::runtime_error("Invalid header! Insert: date,exchange_rate ");
    }

    while (std::getline(file, line))
    {
        size_t separator_pos = line.find(",");
        if (separator_pos == std::string::npos)
            throw std::runtime_error("Invalid line format: " + line);
    
        std::string date = line.substr(0, separator_pos);
        std::string valueStr = line.substr(separator_pos + 1);

        removeSpaces(date);
        removeSpaces(valueStr);

        float exchange_value = stringToFloat(valueStr);
        _data[date] = exchange_value;
    }
    return (0);
}

/* DESTRUCTOR */

BitcoinExchange::~BitcoinExchange() {}

// EXCLUIR DEPOIS

void BitcoinExchange::printData() const {
    if (_data.empty()) {
        std::cout << "No data available in the container." << std::endl;
        return;
    }

    std::cout << "Date       | Exchange Rate" << std::endl;
    std::cout << "--------------------------" << std::endl;
    
    for (std::map<std::string, float>::const_iterator it = _data.begin(); it != _data.end(); ++it) {
        std::cout << it->first << " | " << it->second << std::endl;
    }
}
