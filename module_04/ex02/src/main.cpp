/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:48:21 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/23 15:12:43 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"


static void println(const std::string& str)
{
    std::cout << str << std::endl;
}

int main()
{
    {
        println("=== Subject test ===");
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();
        println("=== Destructor ===");
        delete j;//should not create a leak
        delete i;
        println("~~~~~~~~~~~~~~~~~~");
    }
    {
        println("=== My test ===");
        
        AAnimal* animals[4];
        
        animals[0] = new Cat();
        animals[1] = new Cat();

        animals[2] = new Dog();
        animals[3] = new Dog();

        for (int i = 0; i < 4; i++)
        {
            animals[i]->makeSound();
        }

        println("=== Destructor ===");
        for (int i = 0; i < 4; i++)
            delete animals[i];

        println("~~~~~~~~~~~~~~~");
    }
    {
        println("=== Brain test ===");
        Cat saotra;
        Dog fana;

        saotra.setIdea("eat human");
        saotra.setIdea("code with c");
        saotra.setIdea("drink beer instead of milk");
        saotra.showIdeas();
        saotra.makeSound();

        fana.setIdea("wanna speak english");
        fana.setIdea("learn c++");
        fana.setIdea("live longer");
        fana.setIdea("going to mars");
        fana.showIdeas();
        fana.makeSound();

        println("=== Destructor ===");
    }
    return 0;
}