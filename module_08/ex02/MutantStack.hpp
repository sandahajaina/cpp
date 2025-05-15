/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:11:46 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/15 16:52:22 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {};
        MutantStack(const MutantStack& other) : std::stack<T>(other) {};
        ~MutantStack() {};
        MutantStack& operator=(const MutantStack& other)
        {
            std::stack<T>::operator=(other);
            return *this;
        }   

    private:
        /* data */
};

#endif