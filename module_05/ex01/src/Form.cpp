/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:33:56 by sranaivo          #+#    #+#             */
/*   Updated: 2025/03/25 22:21:30 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

const int Form::_maxGrade = 1;
const int Form::_minGrade = 150;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : 
	_is_signed(false),
	_grade_required_to_sign_it(0),
	_grade_required_to_execute_it(0)
{}

Form::Form( const Form & src ) :
	_name(src._name),
	_is_signed(false),
	_grade_required_to_sign_it(src._grade_required_to_sign_it),
	_grade_required_to_execute_it(src._grade_required_to_execute_it)
{}

Form::Form(std::string name, int sign_grade, int execute_grade) :
	_name(name),
	_is_signed(false),
	_grade_required_to_sign_it(sign_grade),
	_grade_required_to_execute_it(execute_grade)
{
	if (sign_grade < _maxGrade || execute_grade < _maxGrade)
		throw GradeTooHighException();
	else if (sign_grade > _minGrade || execute_grade > _minGrade)
		throw GradeTooLowException();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		_is_signed = rhs.getIsSigned();
		
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << i.getName() << ", " 
		<< "is signed : "
		<< i.getIsSigned() << ", " 
		<< "sign required grade : " 
		<< i.getGradeRequiredToSignIt() << ", "
		<< "execute required grade : "
		<< i.getGradeRequiredToExecuteIt();
	return o;
}


/*
** --------------------------------- EXCEPTION --------------------------------
*/

const char* Form::GradeTooHighException::what() const throw()
{
	return "Error: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Error: Grade too low";
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > _grade_required_to_sign_it)
		throw GradeTooLowException();
	_is_signed = true;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string&	Form::getName() const {return _name;}

bool				Form::getIsSigned() const {return _is_signed;}

int	Form::getGradeRequiredToSignIt() const {return _grade_required_to_sign_it;}

int	Form::getGradeRequiredToExecuteIt() const {return _grade_required_to_execute_it;}

/* ************************************************************************** */