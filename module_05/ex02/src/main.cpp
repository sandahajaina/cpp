/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:22:23 by sranaivo          #+#    #+#             */
/*   Updated: 2025/03/29 16:24:54 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

int main()
{
    {
        ShrubberyCreationForm shrubbery;
        ShrubberyCreationForm coco(shrubbery);

        std::cout << coco.getTarget();
        (void) shrubbery;
    }
    
    return  0;
}