/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:42:30 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/24 17:48:51 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include "../inc/ICharacter.hpp"

// static void println(const std::string& str) 
// {
//     std::cout << str << std::endl;
// }

int main()
{
    ICharacter* me = new Character("me");
    Ice ice;
    ice.use(*me);

    return 0;
}