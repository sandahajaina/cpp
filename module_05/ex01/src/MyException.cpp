/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyException.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:19:07 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 16:46:18 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MyException.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MyException::MyException() {}

MyException::MyException( const MyException & src ) { (void) src;}

MyException::MyException(const char* msg) : _error_message(msg) {}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MyException::~MyException() throw() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MyException &				MyException::operator=( MyException const & rhs )
{
	(void) rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const char* MyException::what() const throw()
{
	return _error_message;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */