#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

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
    ft_println("-- New contact --");
    ft_print("  first name: ");
    std::getline(std::cin, data[0]);
    ft_print("  last name: ");
    std::getline(std::cin, data[1]);
    ft_print("  nickname: ");
    std::getline(std::cin, data[2]);
    ft_print("  phone number: ");
    std::getline(std::cin, data[3]);
    ft_print("  darkest secret: ");
    std::getline(std::cin, data[4]);
}

int main()
{
    PhoneBook phone_book;
    std::string input;

    ft_println("~ My Awesome PhoneBook ~");
    ft_println("You can add, search and exit the program by taping respectively 'ADD', 'SEARCH' and 'EXIT'");
    while (42)
    {
        ft_print("Phonebook> ");
        std::getline(std::cin, input);
        if (input == "ADD")
        {
            std::string data[5];
            get_contact_data(data);
            phone_book.add_contact(data);
        }
        else if (input == "SEARCH")
        {
            ft_println("search...");
        }
        else if (input == "EXIT")
        {
            break;
        }
        else if (input == "print")
            phone_book.print_contacts();
        else
            ft_println("unvalid command...");
    }

    return 0;
}