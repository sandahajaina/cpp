/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:50:32 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 17:01:23 by sranaivo         ###   ########.fr       */
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

// std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!getIsSigned())
	{
		std::cout << "error: form not signed" << '\n';
		return;
	}
	if (executor.getGrade() > getGradeRequiredToExecuteIt())
	{
		std::cout << "the robotomy failed" << '\n';
		throw GradeTooLowException();
	}
	else
	{
		std::cout << _target << " has been robotomized successfully 50\% of the time" << '\n';
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