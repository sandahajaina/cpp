/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:09:20 by sranaivo          #+#    #+#             */
/*   Updated: 2025/06/17 16:07:51 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        RPN rpn;
        rpn.execute(av[1]);
    }
    else
    {
        std::cout << "Error: invalid input\n";
        return 1;
    }
    return 0;
}