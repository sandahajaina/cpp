#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cctype>

// Fonction pour vérifier si une chaîne est non vide
bool is_not_empty(const std::string& str) {
    return !str.empty();
}

// Fonction pour afficher un message en rouge
void print_error(const std::string& message) {
    const std::string red = "\033[31m"; // Code ANSI pour le rouge
    const std::string reset = "\033[0m"; // Réinitialisation des couleurs
    std::cout << red << message << reset << std::endl;
}

// Fonction pour vérifier si une chaîne contient uniquement des chiffres
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
    ft_println("-- New contact --");
    do {
        std::cout << "  first name : ";
        std::getline(std::cin, input);
        if (!is_not_empty(input)) {
            print_error("   Error : the first name can't be empty.");
        }
    } while (!is_not_empty(input));
    data[0] = input;

    do {
        std::cout << "  last name : ";
        std::getline(std::cin, input);
        if (!is_not_empty(input)) {
            print_error("   Error : the last name can't be empty.");
        }
    } while (!is_not_empty(input));
    data[1] = input;

    do {
        std::cout << "  nickname : ";
        std::getline(std::cin, input);
        if (!is_not_empty(input)) {
            print_error("   Error : the nickname can't be empty.");
        }
    } while (!is_not_empty(input));
    data[2] = input;

    do {
        std::cout << "  phone number : ";
        std::getline(std::cin, input);
        if (!is_numeric(input)) {
            print_error("   Error : numeric only.");
        }
    } while (!is_numeric(input));
    data[3] = input;

    do {
        std::cout << "  darkest secret : ";
        std::getline(std::cin, input);
        if (!is_not_empty(input)) {
            print_error("   Error : the darkest secret can't be empty.");
        }
    } while (!is_not_empty(input));
    data[4] = input;
}

int main()
{
    PhoneBook phone_book;
    std::string input;

    std::string data1[5] = {"sanda","hajaina","rahn", "45", "sad"};
    std::string data2[5] = {"bena","hajaina","rahn", "45", "sad"};
    std::string data3[5] = {"dia","hajaina","rahn", "45", "sad"};
    std::string data4[5] = {"aina","hajaina","rahn", "45", "sad"};
    std::string data5[5] = {"ando","hajaina","rahn", "45", "sad"};
    std::string data6[5] = {"saotra","hajaina","rahn", "45", "sad"};
    std::string data7[5] = {"sanih","hajaina","rahn", "45", "sad"};
    std::string data8[5] = {"bolo","hajaina","rahn", "45", "sad"};

    phone_book.add_contact(data1);
            phone_book.add_contact(data2);
            phone_book.add_contact(data3);
            phone_book.add_contact(data4);
            phone_book.add_contact(data5);
            phone_book.add_contact(data6);
            phone_book.add_contact(data7);
            phone_book.add_contact(data8);

    ft_println("~ My Awesome PhoneBook ~");
    ft_println("You can add, search and exit program by taping respectively 'ADD', 'SEARCH' and 'EXIT'");
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
            phone_book.search_contact();
        }
        else if (input == "EXIT")
        {
            break;
        }
        else if (input == "print")
            phone_book.print_contacts();
    }

    return 0;
}