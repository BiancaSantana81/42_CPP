/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/05 16:53:51 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

class RPN
{
    private:

    std::stack<int> _values;

    public:

    //constructors and destructor
    RPN(void);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN(void);

    // methods

    void calculate(std::string input);

    bool validInput(std::string line);
    bool isOperator(std::string token);
    bool isNumber(std::string token);

    int convertNumber(std::string token);

};


#endif