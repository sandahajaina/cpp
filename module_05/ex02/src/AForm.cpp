/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:33:56 by sranaivo          #+#    #+#             */
/*   Updated: 2025/03/27 16:56:33 by sranaivo         ###   ########.fr       */
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

AForm::AForm(std::string name, int sign_grade, int execute_grade) :
	_name(name),
	_is_signed(false),
	_grade_required_to_sign_it(sign_grade),
	_grade_required_to_execute_it(execute_grade)
{
	if (sign_grade < _maxGrade)
		throw GradeTooHighException();
	else if (sign_grade > _minGrade)
		throw GradeTooLowException();
	if (execute_grade < _maxGrade)
		throw GradeTooHighException();
	else if (execute_grade > _minGrade)
		throw GradeTooLowException();
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

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Error: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Error: Grade too low";
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void AForm::beSigned(Bureaucrat& b)
{
	if (getIsSigned())
		throw "Error: form already signed";
	if (b.getGrade() > _grade_required_to_sign_it)
		throw GradeTooLowException();
	_is_signed = true;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string&	AForm::getName() const {return _name;}

bool				AForm::getIsSigned() const {return _is_signed;}

int	AForm::getGradeRequiredToSignIt() const {return _grade_required_to_sign_it;}

int	AForm::getGradeRequiredToExecuteIt() const {return _grade_required_to_execute_it;}

/* ************************************************************************** */