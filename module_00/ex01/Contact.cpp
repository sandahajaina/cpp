/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:02:17 by sranaivo          #+#    #+#             */
/*   Updated: 2024/12/27 14:40:43 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact (
    std::string first_name,
    std::string last_name,
    std::string nick_name,
    std::string phone_number,
    std::string secret
) : first_name(first_name),
    last_name(last_name),
    nick_name(nick_name),
    phone_number(phone_number),
    secret(secret)
{
    // std::cout << this->first_name << std::endl;
    // std::cout << this->last_name << std::endl;
    // std::cout << this->nick_name << std::endl;
    // std::cout << this->phone_number << std::endl;
    // std::cout << this->secret << std::endl;
    return ;
}

const std::string& Contact::get_first_name(void) const
{
    return (this->first_name);
}

const std::string& Contact::get_last_name(void) const
{
    return (this->last_name);
}

const std::string& Contact::get_nick_name(void) const
{
    return (this->nick_name);
}

const std::string& Contact::get_phone_number(void) const
{
    return (this->phone_number);
}

const std::string& Contact::get_secret(void) const
{
    return (this->secret);
}

void    Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}

void    Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}

void    Contact::set_nick_name(std::string nick_name)
{
    this->nick_name = nick_name;
}

void    Contact::set_phone_number(std::string phone_number)
{
    this->phone_number = phone_number;
}

void    Contact::set_secret(std::string secret)
{
    this->secret = secret;
}

Contact::Contact(void)
{
    return ;
}

Contact::~Contact(void)
{
    return ;
}