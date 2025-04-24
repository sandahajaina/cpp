/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:13:57 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/24 10:40:09 by sranaivo         ###   ########.fr       */
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
    std::cout << std::fixed << std::setprecision(1);

    if (isChar(arg))
    {
        char c = arg[0];
        if (c >= 32 && c < 127)
            std::cout << "char: '" << c << "'\n";
        else
            std::cout << "char: Non displayable" << '\n';
        std::cout << "int: " << static_cast<int>(c) << std::endl; 
        std::cout << "float: " << static_cast<float>(c) <<'f' << std::endl; 
        std::cout << "double: " << static_cast<double>(c) << std::endl; 
    }
    else if (isInt(arg))
    {
        int n = atoi(arg.c_str());
        if (n >= 32 && n < 127)
            std::cout << "char: '" << static_cast<char>(n) << "'\n";
        else if (n >= 0 && n < 32)
            std::cout << "char: Non displayable\n";
        else
            std::cout << "char: impossible" << std::endl;
        
        std::cout << "int: " << n << std::endl; 
        std::cout << "float: " << static_cast<float>(n) <<'f' << std::endl; 
        std::cout << "double: " << static_cast<double>(n) << std::endl;        
    }
    else if (isFloat(arg))
    {
        float f = strtof(arg.c_str(), NULL);
        if (std::isnan(f) || std::isinf(f))
            std::cout << "char: impossible\nint: impossible\n";
        else if (f >= 32 && f <= 126)
        {
            std::cout << "char: " << "'" << static_cast<char>(f) << "'\n";
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        }
        else
            std::cout << "char: Non displayable\nint: " << static_cast<int>(f) << '\n';
        std::cout << "float: " << f << "f\n";
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    else if (isDouble(arg))
    {
        double d = strtod(arg.c_str(), NULL);
        if (std::isnan(d) || std::isinf(d))
			std::cout << "char: impossible\nint: impossible\n";
        else if (d >= 32 && d <= 126)
            std::cout << "char: '" << static_cast<char>(d) << "'\n";
        else
            std::cout << "char: non displayable\nint: " << static_cast<int>(d) << '\n';
        
        std::cout << "float: " << static_cast<float>(d) << "f\n";
        std::cout << "double: " << d << '\n';
    }
    else
    {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        std::cout << "float: " << "impossible" << std::endl;
        std::cout << "double: " << "impossible" << std::endl;
    }
}