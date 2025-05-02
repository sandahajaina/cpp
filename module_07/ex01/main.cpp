/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:48:07 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/02 17:05:44 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printElement( const T& element)
{
    std::cout << element << '\n';
}

void printEven(long n)
{
    if (n % 2 == 0)
        std::cout << n << '\n';
}

int main()
{
    std::string str[2] = {"salut", "ca va?"};
    iter<std::string, void(*)(const std::string&)>(str, 2, printElement);

    std::cout << '\n';

    int tab[] = {5, 8, 6};
    iter<int, void(*)(const int&)>(tab, 3, printElement);

    std::cout << '\n';

    char c[] = {'W', 'T', 'F'};
    iter<char, void(*)(const char&)>(c, 3, printElement);

    std::cout << '\n';

    long longTab[] = {1, 42, 3, 100, 56, 9};
    iter(longTab, 5, printEven);

    return 0;
}