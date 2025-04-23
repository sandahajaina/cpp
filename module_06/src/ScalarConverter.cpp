/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:13:57 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/24 02:55:56 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */) {}

ScalarConverter::ScalarConverter(const ScalarConverter & src) {(void) src;}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs) 
{
    (void) rhs;
    return *this;
}

// void ScalarConverter::display() const
// {
    
// }

static bool isChar(const std::string& arg)
{
    return (arg.length() == 1 && !isdigit(arg[0]));
}

static bool isInt(const std::string& arg)
{
    char *pEnd;
    long value = strtol(arg.c_str(), &pEnd, 10);
    return (*pEnd == '\0' &&
            value >= std::numeric_limits<int>::min() &&
            value <= std::numeric_limits<int>::max());
}

static bool isFloat(const std::string& arg)
{
    if (arg == "-inff" || arg == "+inff" || arg == "nanf")
        return true;
    char *pEnd;
    strtof(arg.c_str(), &pEnd);
    return (*pEnd == 'f' && *(pEnd + 1) == '\0'); // a tester avec 0.42
}

static bool isDouble(const std::string& arg)
{
    if (arg == "-inf" || arg == "+inf" || arg == "nan")
        return true;
    char *pEnd;
    strtod(arg.c_str(), &pEnd);
    return (*pEnd == '\0');
}

void ScalarConverter::convert(const std::string& arg)
{   
    if (isChar(arg))
    {
        std::cout << "char\n";
    }
    else if (isInt(arg))
    {
        std::cout << "int\n";
    }
    else if (isFloat(arg))
    {
        std::cout << "float\n";
    }
    else if (isDouble(arg))
    {
        std::cout << "double\n";
    }

    // std::cout << "char: " << "value" << std::endl;
    // std::cout << "int: " << "value" << std::endl; 
    // std::cout << "float: " << "value" << std::endl; 
    // std::cout << "double: " << "value" << std::endl; 
}