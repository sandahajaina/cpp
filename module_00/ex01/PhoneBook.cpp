/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:33:30 by sranaivo          #+#    #+#             */
/*   Updated: 2024/12/30 17:05:44 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cstdio>

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

void PhoneBook::print_contact(int id)
{
    for (int i = 0; i < this->_size; i++)
    {
        if (this->_contact[i].get_id() == id)
        {
            std::cout << "\033[32m";
            std::cout << "      Index :          " << this->_contact[i].get_id() << std::endl;
            std::cout << "      First name :     " << this->_contact[i].get_first_name() << std::endl;
            std::cout << "      Last name :      " << this->_contact[i].get_last_name() << std::endl;
            std::cout << "      Nickname :       " << this->_contact[i].get_nick_name() << std::endl;
            std::cout << "      Phone number :   " << this->_contact[i].get_phone_number() << std::endl;
            std::cout << "      Darkest secret : " << this->_contact[i].get_secret() << std::endl;
            std::cout << "\033[0m";
            break;
        }
    }
}

void PhoneBook::search_contact()
{
    if (this->_size == 0)
    {
        std::cout << "\033[31m" << "      No contacts have been added yet." << "\033[0m" << std::endl;
        return ;
    }
    std::cout << "\033[33m";
    this->display_contacts();

    int input;
    std::string input_str;
    while (true)
    {
        std::cout << "\033[0m" << "      Contact index : ";
        std::getline(std::cin, input_str);

        if (input_str.empty()) { 
            std::cout << "\033[31m" << "      Error : please enter a valid index." << "\033[0m" << std::endl;
            continue;
        }

        bool valid = true;
        size_t i = 0;
        while (i < input_str.length()) {
            if (!isdigit(input_str[i])) {
                valid = false;
                break;
            }
            ++i;
        }
        
        if (valid) {
            input = 0;
            for (i = 0; i < input_str.length(); ++i) {
                input = input * 10 + (input_str[i] - '0');
            }
            break;
        } else {
            std::cout << "\033[31m" << "      Error : insert a valid index." << "\033[0m" << std::endl;
        }
    }

    if (check_contact_id(input))
        this->print_contact(input);
    else
        std::cout << "\033[31m" << "      No contact found." << "\033[0m" << std::endl;
    
    std::cout << "\033[0m";
}

void PhoneBook::display_contacts()
{
    if (!(this->_size))
        return;
    int old = this->get_oldest_contact();
    
    std::cout << "     Index" << "|"
              << "First name" << "|"
              << " Last name" << "|"
              << " Nick name" << std::endl;
    std::cout << "     --------------------------------------" << std::endl;
    
    for (int i = 0; i < this->_size; i++)
    {
        for (int j = 0; j < this->_size; j++)
        {
            if (this->_contact[j].get_id() == old)
            {
                format_number(this->_contact[j].get_id());
                std::cout << "|";
                format_text(this->_contact[j].get_first_name());
                std::cout << "|";
                format_text(this->_contact[j].get_last_name());
                std::cout << "|";
                format_text(this->_contact[j].get_nick_name());
                std::cout << std::endl;
                break;
            }
        }
        old++;
    }
    std::cout << "     --------------------------------------" << std::endl;
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

bool  PhoneBook::check_contact_id(int id)
{
    for (int i = 0; i < this->_size; i++)
    {
        if (this->_contact[i].get_id() == id)
            return true;
    }
    return false;
}

void PhoneBook::format_text(const std::string& input)
{
    const size_t width = 10;
    std::string str = input;

    if (str.length() > width) {
        str = str.substr(0, width - 1) + ".";
    }
    while (str.length() < width) {
        str = " " + str;
    }

    std::cout << str;
}

std::string PhoneBook::int_to_string(int number)
{
    std::string result;

    do {
        result = static_cast<char>((number % 10) + '0') + result;
        number /= 10;
    } while (number > 0);

    return result;
}

void PhoneBook::format_number(int number)
{
    const size_t width = 10;
    std::string str = int_to_string(number);

    while (str.length() < width) {
        str = " " + str;
    }

    std::cout << str;
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

PhoneBook::PhoneBook() : _size(0) {}

PhoneBook::~PhoneBook() {}