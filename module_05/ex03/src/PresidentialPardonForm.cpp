/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:08:36 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/10 12:42:28 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("presidential pardon", 25, 5, "default") {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) :
	AForm("presidential pardon", 25, 5, src.getTarget()) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	AForm("presidential pardon", 25, 5, target) {}


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
		std::cout << "Error: form not signed" << '\n';
		return;
	}
	if (executor.getGrade() > getGradeRequiredToExecuteIt())
		throw GradeTooLowException("Error: the executor's grade is too low");

	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << '\n';
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */