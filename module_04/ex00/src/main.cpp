/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:48:21 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/22 15:31:04 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongCat.hpp"

static void print(std::string str)
{
    std::cout << str;
}

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }
    std::cout << std::endl << "=== Dog test ===" << std::endl;
    {
        const Animal *saotra = new Dog();
        print("[MakeSound] ");
        saotra->makeSound();
        delete saotra;
    }
    std::cout << std::endl << "=== Cat test ===" << std::endl;
    {
        const Animal *saotra = new Cat();
        print("[MakeSound] ");
        saotra->makeSound();
        delete saotra;
    }
    std::cout << std::endl << "=== WrongAnimal test ===" << std::endl;
    {
        WrongAnimal* saotra = new WrongAnimal();
        WrongAnimal* andria = new WrongCat();
        print("[WrongAnimal] makeSound() : ");
        saotra->makeSound();
        print("[WrongCat] makeSound() : ");
        andria->makeSound();
        delete saotra;
        delete andria;
    }
    return 0;
}