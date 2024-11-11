/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:41:16 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/11 10:44:11 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>

#include "parsing.hpp"

class BitcoinExchange
{
    private:
    
    std::map<std::string, float> _data;

    public:

   // constructors and destructor

    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange(void);

    // methods

    int  populatingContainer(std::string csv);
    void loadingData(std::ifstream &file);
    void formatData(const std::string &line);
    bool validateAndExtractData(const std::string &line, std::string &date, float &value);
    void convertValue(const std::string &date, float value);

};

#endif