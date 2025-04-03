/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:50:32 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/03 16:39:17 by sranaivo         ###   ########.fr       */
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
	AForm("robotomy request", 72, 54), _target(target) {}


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
	for (int i = 0; i < 5000000; i++)
		std::cout << '\a';
	
	if (!getIsSigned())
		throw "error: form not signed";

	if (executor.getGrade() > getGradeRequiredToExecuteIt())
		throw GradeTooLowException();

	if (std::rand() % 2 != 0)
		std::cout << _target << " has been robotomized successfully" << '\n';
	else
		throw "the robotomy failed";
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


const std::string& RobotomyRequestForm::getTarget() const
{
	return _target;
}


/* ************************************************************************** */