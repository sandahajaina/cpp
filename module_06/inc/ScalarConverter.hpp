/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:49:40 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/24 02:57:11 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

class ScalarConverter
{
    private:
        ScalarConverter(/* args */);
        ScalarConverter(const ScalarConverter & src);
        ScalarConverter& operator=(const ScalarConverter & rhs);
        ~ScalarConverter();

    public:
        static void convert(const std::string&);
};


#endif
