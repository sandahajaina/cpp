/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:08:30 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/04 22:08:44 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<std::string> names(3);
    names[0] = "sanda";
    names[1] = "hajaina";
    names[2] = "ranaivoarisoa";

    std::cout << "names[0]: " << names[0] << '\n';
    std::cout << "names[1]: " << names[1] << '\n';
    std::cout << "names[2]: " << names[2] << '\n';

    Array<std::string> names1(names);
    Array<std::string> names2;
    names2 = names1;

    std::cout << "\nnames2[0]: " << names2[0] << '\n';
    std::cout << "names2[1]: " << names2[1] << '\n';
    std::cout << "names2[2]: " << names2[2] << '\n';

    Array<int> ages(2);
    ages[0] = 22;
    ages[1] = 25;

    std::cout << "\nages[0]: " << ages[0] << '\n';
    std::cout << "ages[1]: " << ages[1] << '\n';

    try
    {
        std::cout << '\n' << ages[5];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}