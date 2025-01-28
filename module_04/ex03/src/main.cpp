/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:42:30 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/28 16:18:16 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/MateriaSource.hpp"

static void println(const std::string& str) 
{
    std::cout << str << std::endl;
}

int main()
{
    {
        println ("=== Subject test ===");

        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");

        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter* bob = new Character("bob");

        me->use(0, *bob);
        me->use(1, *bob);
        
        delete bob;
        delete me;
        delete src;
        println ("=== === === === ===");
    }
    {
        println("");
        println ("=== My test ===");
        
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* saotra = new Character("saotra");
        AMateria* materia;
        
        materia = src->createMateria("cure");
        saotra->equip(materia);

        materia = src->createMateria("ice");
        saotra->equip(materia);

        materia = src->createMateria("cure");
        saotra->equip(materia);
        
        materia = src->createMateria("ice");
        saotra->equip(materia);

        ICharacter* andria = new Character("andria");

        println("saotra->use(1, *andria); => does nothing because idx [1] does not exist");
        saotra->use(1, *andria);
        
        saotra->use(0, *andria);

        saotra->unequip(0);
        
        println("saotra try to use idx[0] materia : UNEQUIPPED");
        saotra->use(0, *andria);
        
        println("saotra uses idx[3] materia :");
        saotra->use(3, *andria);

        println("");
        for (int i = 0; i < 4; i++)
        {
            saotra->use(i, *andria);
        }
        println("");

        saotra->unequip(3);

        println("");
        for (int i = 0; i < 4; i++)
        {
            saotra->use(i, *andria);
        }
        println("");

        println("adding 2 materias for saotra");
        materia = src->createMateria("cure");
        saotra->equip(materia);
        materia = src->createMateria("ice");
        saotra->equip(materia);

        println("");
        for (int i = 0; i < 4; i++)
        {
            saotra->use(i, *andria);
        }

        delete andria;
        delete saotra;
        delete src;
        println ("=== === === ===");
    }
    {
        println("");
        println("=== Deep copy test for the character ===");

        Character saotra("saotra");
        Character andria("andria");

        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        AMateria* m = src->createMateria("ice");
        saotra.equip(m);
        m = src->createMateria("cure");
        saotra.equip(m);
        m = src->createMateria("ice");
        saotra.equip(m);
        m = src->createMateria("cure");
        saotra.equip(m);

        andria = saotra;
        
        for (int i = 0; i < 4; i++)
        {
            andria.use(i, saotra);
        }
        delete src;
    }

    return 0;
}