/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:49:40 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/17 13:58:42 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
    private:
        /* data */
    public:
        ScalarConverter(/* args */);
        ScalarConverter(const ScalarConverter & src);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter & rhs);

        static void convert(std::string); 
};

ScalarConverter::ScalarConverter(/* args */)
{
}

ScalarConverter::~ScalarConverter()
{
}


#endif
