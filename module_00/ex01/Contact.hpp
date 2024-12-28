/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:02:41 by sranaivo          #+#    #+#             */
/*   Updated: 2024/12/28 17:11:15 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
    private:
        int         id;
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string secret;
        
    public:
        int                 get_id(void) const;
        const std::string&	get_first_name(void) const;
        const std::string&	get_last_name(void) const;
        const std::string&	get_nick_name(void) const;
        const std::string&	get_phone_number(void) const;
        const std::string&  get_secret(void) const;
        void    set_id(int id);
        void    set_first_name(std::string first_name);
        void    set_last_name(std::string last_name);
        void    set_nick_name(std::string nick_name);
        void    set_phone_number(std::string phone_number);
        void    set_secret(std::string secret);
        Contact(void);
        Contact(
            int         id,
            std::string first_name,
            std::string last_name,
            std::string nick_name,
            std::string phone_number,
            std::string secret
        );
        ~Contact(void);
};

#endif