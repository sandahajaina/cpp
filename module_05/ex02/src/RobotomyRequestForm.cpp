/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:50:32 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 23:50:11 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) :
	AForm("robotomy request", 72, 45), _target(src._target) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	AForm("robotomy request", 72, 45), _target(target) {}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	(void) rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	for (int i = 0; i < 5000000; i++)
		std::cout << '\a';
	
	if (!getIsSigned())
		throw "error: form not signed";

	try
	{
		if (executor.getGrade() > getGradeRequiredToExecuteIt())
			throw GradeTooLowException("Error: the executor's grade is too low");

		if (std::rand() % 2 != 0)
			std::cout << _target << " has been robotomized successfully" << '\n';
		else
			throw "the robotomy failed";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const char* e)
	{
		std::cout << e << '\n';
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


const std::string& RobotomyRequestForm::getTarget() const
{
	return _target;
}


/* ************************************************************************** */