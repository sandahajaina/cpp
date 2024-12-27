/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:00:28 by sranaivo          #+#    #+#             */
/*   Updated: 2024/12/27 16:28:56 by sranaivo         ###   ########.fr       */
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
        
    public:
        PhoneBook(/* args */);
        ~PhoneBook();
        void    add_contact();
        void    search_contact();
};

#endif