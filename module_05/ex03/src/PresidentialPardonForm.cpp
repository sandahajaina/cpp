/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 15:08:36 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/01 14:49:18 by sranaivo         ###   ########.fr       */
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

// std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/


void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!getIsSigned())
	{
		std::cerr << "error: form not signed" << '\n';
		return;
	}
	if (executor.getGrade() > getGradeRequiredToExecuteIt())
		throw GradeTooLowException();
	else
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << '\n';
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& PresidentialPardonForm::getTarget() const {return _target;}


/* ************************************************************************** */