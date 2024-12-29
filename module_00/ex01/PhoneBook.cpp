/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:33:30 by sranaivo          #+#    #+#             */
/*   Updated: 2024/12/30 01:11:38 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <stdio.h>
#include <iomanip>

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

void PhoneBook::search_contact()
{
    this->display_contacts();
}

std::string PhoneBook::format_text(const std::string& text, size_t width)
{
    std::string formatted = text;
    if (formatted.length() > width) {
        formatted = formatted.substr(0, width - 1) + ".";
    }
    return formatted;
}

void PhoneBook::display_contacts()
{
    if (!(this->_size))
        return;
    int old = this->get_oldest_contact();
    
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First name" << "|"
              << std::setw(10) << "Last name" << "|"
              << std::setw(10) << "Nick name" << std::endl;
    std::cout << "     --------------------------------------" << std::endl;
    
    for (int i = 0; i < this->_size; i++)
    {
        for (int j = 0; j < this->_size; j++)
        {
            if (this->_contact[j].get_id() == old)
            {
                std::cout << std::setw(10) << this->_contact[j].get_id() << "|"
                  << std::setw(10)
                  << format_text(this->_contact[j].get_first_name(), 10) << "|"
                  << std::setw(10)
                  << format_text(this->_contact[j].get_last_name(), 10) << "|"
                  << std::setw(10)
                  << format_text(this->_contact[j].get_nick_name(), 10) << std::endl;
                break;
            }
        }
        old++;
    }
}

PhoneBook::PhoneBook() : _index(0), _size(0) {}

PhoneBook::~PhoneBook() {}