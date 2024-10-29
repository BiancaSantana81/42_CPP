/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:41:16 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/29 18:12:01 by bsantana         ###   ########.fr       */
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

#include "init.hpp"

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

    void formatData(std::string line);
    void loadingData(std::ifstream &file);
    int  populatingContainer(std::string csv);


    // EXCLUIR AO FINAL DO EXERCÍCIO
    void    printData() const;
};

#endif