/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:33:30 by sranaivo          #+#    #+#             */
/*   Updated: 2024/12/28 17:17:37 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <stdio.h>

void    PhoneBook::add_contact(std::string data[5])
{
    int id = (this->_size) ? (this->get_latest_contact() + 1) : 0;
    if (this->_size >= 8)
    {
        id = this->get_oldest_contact();
        for (int i = 0; i < 8; i++)
        {
            if (this->_contact[i].get_id() == id)
            {
                this->_contact[i].set_id(this->get_latest_contact() + 1);
                this->_contact[i].set_first_name(data[0]);
                this->_contact[i].set_last_name(data[1]);
                this->_contact[i].set_nick_name(data[2]);
                this->_contact[i].set_phone_number(data[3]);
                this->_contact[i].set_secret(data[4]);
                break ;
            }
        }
    }
    else
    {
        this->_contact[this->_size] = Contact(
            id,
            data[0],
            data[1],
            data[2],
            data[3],
            data[4]
        );
        this->_size++;

    }
}

int PhoneBook::get_oldest_contact()
{
    int id = (this->_size) ? this->_contact[0].get_id() : 0;
    int i = 0;
    while (i < this->_size)
    {
        if (id > this->_contact[i].get_id())
            id = this->_contact[i].get_id();
        i++;
    }
    return (id);
}

int PhoneBook::get_latest_contact()
{
    int id = (this->_size) ? this->_contact[0].get_id() : 0;
    int i = 0;
    while (i < this->_size)
    {
        if (id < this->_contact[i].get_id())
            id = this->_contact[i].get_id();
        i++;
    }
    return (id);
}

void PhoneBook::print_contacts()
{
    int i = 0;
    while (i < this->_size)
    {
        std::cout << this->_contact[i].get_id() << " : " << this->_contact[i].get_first_name() << std::endl;
        i++;
    }
}

PhoneBook::PhoneBook() : _index(0), _size(0) {}

PhoneBook::~PhoneBook() {}