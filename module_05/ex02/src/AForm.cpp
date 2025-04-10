/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:33:56 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/10 12:56:59 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

const int AForm::_maxGrade = 1;
const int AForm::_minGrade = 150;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : 
	_is_signed(false),
	_grade_required_to_sign_it(0),
	_grade_required_to_execute_it(0)
{}

AForm::AForm( const AForm & src ) :
	_name(src._name),
	_is_signed(false),
	_grade_required_to_sign_it(src._grade_required_to_sign_it),
	_grade_required_to_execute_it(src._grade_required_to_execute_it)
{}

AForm::AForm(std::string name, int sign_grade, int execute_grade, std::string target) :
	_name(name),
	_is_signed(false),
	_grade_required_to_sign_it(sign_grade),
	_grade_required_to_execute_it(execute_grade),
	_target(target)
{
	try
	{
		if (sign_grade < _maxGrade)
			throw GradeTooHighException("Error: the grade required to sign it is too high");
		else if (sign_grade > _minGrade)
			throw GradeTooLowException("Error: the grade required to sign it is too low");
		if (execute_grade < _maxGrade)
			throw GradeTooHighException("Error: the grade required to execute it is too high");
		else if (execute_grade > _minGrade)
			throw GradeTooLowException("Error: the grade required to execute it is too low");	
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		_is_signed = rhs.getIsSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
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

AForm::GradeTooHighException::GradeTooHighException(const char* msg) :
	MyException(msg) {}

AForm::GradeTooLowException::GradeTooLowException(const char* msg) :
	MyException(msg) {}


/*
** --------------------------------- METHODS ----------------------------------
*/

void AForm::beSigned(Bureaucrat& b)
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

const std::string&	AForm::getName() const {return _name;}

bool				AForm::getIsSigned() const {return _is_signed;}

int	AForm::getGradeRequiredToSignIt() const {return _grade_required_to_sign_it;}

int	AForm::getGradeRequiredToExecuteIt() const {return _grade_required_to_execute_it;}

const std::string& AForm::getTarget() const {return _target;}

/* ************************************************************************** */