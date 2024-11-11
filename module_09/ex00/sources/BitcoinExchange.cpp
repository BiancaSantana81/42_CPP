/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:41:19 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/11 18:02:33 by bsantana         ###   ########.fr       */
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

/*
    This method reads the values from the .csv file and stores them in the `_data` container.
    The `std::map` container was chosen to enable efficient searching using a key-value structure,
    where the key is the date and the value is the corresponding exchange rate.
    If the file cannot be opened or the initial header does not match what is expected, an exception will be thrown.
    The method ignores spaces around the fields and validates the format of the lines,
    ensuring that they are in “date,value” format before adding them to the container.
*/

int BitcoinExchange::populatingContainer(std::string csv)
{
    std::ifstream file(csv.c_str());

    if (!file)
    {
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

/*
    This method reads the entries from the .txt file and checks if it contains the expected header: `date | value`.
    If the header is valid, the method processes each line of the .txt file and ignores empty lines.
    Each entry is then passed to the `formatData` method, which validates and converts the value 
    to the Bitcoin exchange rate, ensuring that only correctly formatted and validated data is processed. 
    and validated data is processed.
*/

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

/*
   Main method: data validation and conversion flow in .txt.
   Receives a line from the .txt file, validates it and extracts the date and value.
   If validation is successful, calls the method to convert the value.
*/

void BitcoinExchange::formatData(const std::string &line)
{
    std::string date;
    float value;

    if (validateAndExtractData(line, date, value))
        convertValue(date, value);
}

/*
    Method to validate and extract values from .txt.
    Receives an input line, checks that the line contains a valid format (date | value).
    Extracts the date and value, removing whitespace.
    Returns true if validation is successful and the output variables 'date' and 'value' are filled.
    Otherwise, prints the appropriate error message and returns false.
*/

bool BitcoinExchange::validateAndExtractData(const std::string &line, std::string &date, float &value)
{
    std::string trimmed_line = line;
    removeSpaces(trimmed_line);
    size_t separator_pos = trimmed_line.find_first_of("|");

    if (separator_pos == std::string::npos) {
        std::cout << BRIGHT_RED "Error: bad input => " RESET << line << std::endl;
        return false;
    }

    date = trimmed_line.substr(0, separator_pos);
    std::string valueStr = trimmed_line.substr(separator_pos + 1);

    removeSpaces(date);
    removeSpaces(valueStr);

    if (valueStr.empty()) {
        std::cout << BRIGHT_RED "Error: missing value for date => " RESET << date << std::endl;
        return false;
    }

    try {
        validateDate(date);
    } catch (const std::runtime_error &e) {
        std::cout << BRIGHT_RED "Error: invalid date => " RESET << date << std::endl;
        return false;
    }

    try {
        value = validateValue(valueStr);
    } catch (const std::runtime_error &e) {
        std::string errMsg = e.what();
        if (errMsg == "negative")
            std::cout << BRIGHT_RED "Error: not a positive number." RESET << std::endl;
        else if (errMsg == "too large")
            std::cout << BRIGHT_RED "Error: too large a number." RESET << std::endl;
        else if (errMsg == "invalid")
            std::cout << BRIGHT_RED "Error: converting value." << RESET << std::endl;
        return false;
    }

    return true;
}

/*
    Method for converting the value using the nearest available exchange rate.
    Receives a date and an amount to be converted.
    Searches for the exchange rate corresponding to the date or the nearest previous one.
    If a rate is found, calculates and displays the converted value.
    Otherwise, it prints an error message indicating that the rate was not found for the given date.
*/

void BitcoinExchange::convertValue(const std::string &date, float value)
{
    std::map<std::string, float>::iterator closest_it = _data.end();

    for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); ++it) {
        if (it->first == date)
        {
            closest_it = it;
            break ;
        }
        else if (it->first < date)
            closest_it = it;
        else
            break ;
    }

    if (closest_it == _data.end())
    {
        std::cout << BRIGHT_RED "Error: exchange rate not found for date => " RESET << date << std::endl;
        return ;
    }

    float convertedValue = value * closest_it->second;
    std::cout << date << " => " << value << " = " << std::fixed << std::setprecision(2) << convertedValue << std::endl;
}

/* DESTRUCTOR */

BitcoinExchange::~BitcoinExchange() {}
