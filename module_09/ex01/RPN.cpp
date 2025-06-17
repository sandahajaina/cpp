/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:13:47 by sranaivo          #+#    #+#             */
/*   Updated: 2025/06/17 16:11:01 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

void RPN::execute(const std::string& str)
{
    int i = -1;
    while (str[++i])
    {
        if (isdigit(str[i]))
        {
            if(isdigit(str[i + 1]))
            {
                std::cout << "Error: number > 9\n";
                return ;
            }
            else
            {
                _stack.push(str[i] - 48);
            }
        }
        else if (str[i] == '+')
        {
            if (_stack.size() < 2)
            {
                std::cout << "Error: invalid input\n";
                return ;
            }
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();
            _stack.push(b + a);
            continue;
        }
        else if (str[i] == '-')
        {
            if (_stack.size() < 2)
            {
                std::cout << "Error: invalid input\n";
                return ;
            }
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();
            _stack.push(b - a);
            continue;
        }
        else if (str[i] == '*')
        {
            if (_stack.size() < 2)
            {
                std::cout << "Error: invalid input\n";
                return ;
            }
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();
            _stack.push(b * a);
            continue;
        }
        else if (str[i] == '/')
        {
            if (_stack.size() < 2)
            {
                std::cout << "Error: invalid input\n";
                return ;
            }
            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            if (a == 0)
            {
                std::cout << "Error: division by zero\n";
                return;
            }
            _stack.pop();
            _stack.push(b / a);
            continue;
        }
        else if (str[i] == ' ')
        {
            continue;
        }
        else
        {
            std::cout << "Error: invalid input\n";
            return;
        }
    }
    if (_stack.size() == 1)
    {
        std::cout << _stack.top() << '\n';
    }
}