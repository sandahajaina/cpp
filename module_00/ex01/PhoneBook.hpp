/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:00:28 by sranaivo          #+#    #+#             */
/*   Updated: 2024/12/30 16:53:47 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
    private:
        Contact _contact[8];
        int     _size;
        
    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact(std::string data[5]);
        void search_contact();
        void print_contact(int id);
        void display_contacts();
        int  get_oldest_contact();
        int  get_latest_contact();
        bool check_contact_id(int id);
        void format_text(const std::string& input);
        void format_number(int number);
        std::string int_to_string(int number);
};

#endif