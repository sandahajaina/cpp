/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:00:28 by sranaivo          #+#    #+#             */
/*   Updated: 2024/12/28 17:02:37 by sranaivo         ###   ########.fr       */
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
        int     _index;
        int     _size;
        
    public:
        PhoneBook();
        ~PhoneBook();
        void add_contact(std::string data[5]);
        void search_contact();
        int  get_oldest_contact();
        int  get_latest_contact();
        void print_contacts();
};

#endif