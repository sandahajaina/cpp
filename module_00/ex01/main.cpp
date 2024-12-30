/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:49:26 by sranaivo          #+#    #+#             */
/*   Updated: 2024/12/30 13:51:29 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cctype>

bool is_not_empty(const std::string& str) {
    return !str.empty();
}

void print_error(const std::string& message) {
    const std::string red = "\033[31m";
    std::cout << red << message << "\033[35m" << std::endl;
}

bool is_numeric(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void ft_println(std::string str)
{
    std::cout << str << std::endl;
}

void ft_print(std::string str)
{
    std::cout << str;
}

void get_contact_data(std::string data[])
{
    std::string input;
    std::cout << "\033[35m" << "      -- NEW CONTACT --" << std::endl;
    do {
        std::cout << "      first name : ";
        std::getline(std::cin, input);
        if (!is_not_empty(input)) {
            print_error("       This field is required.");
        }
    } while (!is_not_empty(input));
    data[0] = input;

    do {
        std::cout << "      last name : ";
        std::getline(std::cin, input);
        if (!is_not_empty(input)) {
            print_error("       This field is required.");
        }
    } while (!is_not_empty(input));
    data[1] = input;

    do {
        std::cout << "      nickname : ";
        std::getline(std::cin, input);
        if (!is_not_empty(input)) {
            print_error("       This field is required.");
        }
    } while (!is_not_empty(input));
    data[2] = input;

    do {
        std::cout << "      phone number : ";
        std::getline(std::cin, input);
        if (!is_numeric(input)) {
            print_error("       Numeric values only.");
        }
    } while (!is_numeric(input));
    data[3] = input;

    do {
        std::cout << "      darkest secret : ";
        std::getline(std::cin, input);
        if (!is_not_empty(input)) {
            print_error("       This field is required.");
        }
    } while (!is_not_empty(input));
    data[4] = input;
    std::cout << "\033[0m";
}

int main()
{
    PhoneBook phone_book;
    std::string input;

    std::cout << "\033[1;35m" << "~ My Awesome PhoneBook ~" << "\033[0m" << std::endl;
    ft_println("You can add, search, or exit the program by typing 'ADD', 'SEARCH', or 'EXIT', respectively.");
    while (42)
    {
        std::cout << "phonebook> ";
        std::getline(std::cin, input);
        if (input == "ADD")
        {
            std::string data[5];
            get_contact_data(data);
            phone_book.add_contact(data);
        }
        else if (input == "SEARCH")
        {
            phone_book.search_contact();
        }
        else if (input == "EXIT")
        {
            break;
        }
    }

    return 0;
}