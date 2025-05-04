/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:40:08 by sranaivo          #+#    #+#             */
/*   Updated: 2025/05/04 21:50:39 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>
class Array
{
    public:
        Array() :  _array(NULL), _size(0) {}

        Array(unsigned int n) : _array(new T[n]), _size(n)
        {
            for (unsigned int i = 0; i < n; i++)
                _array[i] = T();
        }

        Array(const Array & src) : _array(NULL), _size(0)
        {
            *this = src;
        }
        
        Array& operator=(const Array& other)
        {
            if (this != &other)
            {
                delete[] _array;
                _size = other._size;
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = other._array[i];
            }
            return *this;
        }

        ~Array() {delete[] _array;}

        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }

        const T& operator[](unsigned int index) const
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _array[index];
        }
        
        unsigned int size() const { return _size; }

    private:
        T*              _array;
        unsigned int    _size;
};

#endif