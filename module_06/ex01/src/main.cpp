/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:39:38 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/29 11:42:11 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main()
{
    Data data;
    data.name = "Ades";
    data.age = 4250;

    std::cout << "<data>\n";
    std::cout << "data.name: " << data.name << '\n';
    std::cout << "data.age: " << data.age << '\n';

    std::cout << '\n';

    uintptr_t n = Serializer::serialize(&data);
    std::cout << "serialized data <n>: " << n << '\n';

    std::cout << '\n';
    
    Data* data1 = Serializer::deserialize(n);

    std::cout << "<data1> deserialized(n)\n";
    std::cout << "data1->name: " << data1->name << '\n';
    std::cout << "data1->age: " << data1->age << '\n';

    return 0;
}