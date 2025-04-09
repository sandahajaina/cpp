/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:33:56 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 17:25:10 by sranaivo         ###   ########.fr       */
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
	try
	{
		if (sign_grade < _maxGrade)
			throw GradeTooHighException("Error: grade required to sign it too high");
		else if (sign_grade > _minGrade)
			throw GradeTooLowException("Error: grade required to sign it too low");
		if (execute_grade < _maxGrade)
			throw GradeTooHighException("Error: grade required to execute it too high");
		else if (execute_grade > _minGrade)
			throw GradeTooLowException("Error: grade required to execute it too low");	
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
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
		<< ((i.getIsSigned()) ? "true" : "false") << ", " 
		<< "grade required to sign it : " 
		<< i.getGradeRequiredToSignIt() << ", "
		<< "grade required to execute it : "
		<< i.getGradeRequiredToExecuteIt();
	return o;
}


/*
** --------------------------------- EXCEPTION --------------------------------
*/

Form::GradeTooHighException::GradeTooHighException(const char* msg) :
	MyException(msg) {}

Form::GradeTooLowException::GradeTooLowException(const char* msg) :
	MyException(msg) {}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat& b)
{
	if (getIsSigned())
		throw "Error: form already signed";
	if (b.getGrade() > _grade_required_to_sign_it)
		throw GradeTooLowException("Error: the bureaucrat's grade is too low");
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