/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyException.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:14:10 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 16:46:05 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYEXCEPTION_HPP
# define MYEXCEPTION_HPP

# include <iostream>
# include <string>
# include <exception>

class MyException : public std::exception
{

	public:

		MyException();
		MyException(const char *msg);
		MyException( MyException const & src );
		virtual ~MyException() throw();

		MyException &		operator=( MyException const & rhs );

		virtual const char* what() const throw();

	protected:
		const char* _error_message;

};

#endif /* ***************************************************** MYEXCEPTION_H */