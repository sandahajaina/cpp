/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 11:59:44 by sranaivo          #+#    #+#             */
/*   Updated: 2025/06/17 16:10:58 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

class RPN
{
	public:
		RPN();
		~RPN();
		void execute(const std::string&);

	private:
		std::stack<int> _stack;
};