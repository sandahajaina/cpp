/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:23:15 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/08 16:58:33 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int Bureaucrat::_maxGrade = 1;
int Bureaucrat::_minGrade = 150;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	try
	{
		if (grade > 150)
			throw GradeTooLowException();
		else if (grade < 1)
			throw GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src._name), _grade(src._grade) {}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", " << "bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::incrementGrade()
{
	if (_grade - 1 < _maxGrade)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade + 1 > _minGrade)
		throw GradeTooLowException();
	++_grade;
}


/*
** --------------------------------- EXCEPTIONS --------------------------------
*/

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& msg) :
	Bureaucrat::GradeTooHighException::_error_message(msg){}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: Grade too low";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Bureaucrat::getName() const {return _name;}

int Bureaucrat::getGrade() const {return _grade;}


/* ************************************************************************** */