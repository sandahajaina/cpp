/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:08:36 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 23:10:24 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("presidential pardon", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) :
	AForm("presidential pardon", 25, 5), _target(src._target) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("presidential pardon", 25, 5), _target(target) {}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	(void) rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!getIsSigned())
	{
		std::cout << "error: form not signed" << '\n';
		return;
	}
	try
	{
		if (executor.getGrade() > getGradeRequiredToExecuteIt())
			throw GradeTooLowException("Error: the executor's grade is too low");

		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << '\n';
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& PresidentialPardonForm::getTarget() const {return _target;}


/* ************************************************************************** */