/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:54:22 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/28 15:29:18 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SESERIALIZER_HPP

#include <iostream>
#include <cstdint>

typedef struct s_data
{
    int x;
    int y;
} Data;

class Serializer
{
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

    private:
        Serializer();
        Serializer(Serializer const & src);
        Serializer& operator=(Serializer const & rhs);
        ~Serializer();
};

Serializer::Serializer(/* args */)
{
}

Serializer::~Serializer()
{
}


#endif