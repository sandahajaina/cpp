/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:26:03 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/08 15:32:28 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char** argv)
{
    Harl harl;
  
    if (argc == 2)
    {
        harl.complain(argv[1]);
    }
    else
    {
        harl.complain("DEBUG");
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
        harl.complain("UNKNOWN");
    }

    return 0;
}