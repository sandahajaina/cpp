/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:56:22 by sranaivo          #+#    #+#             */
/*   Updated: 2025/01/08 15:42:18 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
    private:
        void debug() const;
        void info() const;
        void warning() const;
        void error() const;

    public:
        void complain(std::string level);
        void filter(std::string level);
        Harl(/* args */);
        ~Harl();
};

#endif