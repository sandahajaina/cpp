/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:00:03 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 17:01:23 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern() {}

Intern::Intern( const Intern & src )
{
	(void) src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void) rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

AForm* Intern::makeForm(const std::string& form_name, const std::string& form_target) const
{
	int form_type = -1;

	const std::string forms[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (form_name == forms[i])
		{
			form_type = i;
			break;
		}
	}

	if (form_type == -1)
	{
		std::cout << "the provided form name does not exist" << '\n';
		return (NULL);
	}
	
	switch (form_type)
	{
	case 0:
		std::cout << "Intern creates " << form_name << '\n';
		return (new ShrubberyCreationForm(form_target));
		break;
	case 1:
		std::cout << "Intern creates " << form_name << '\n';
		return (new RobotomyRequestForm(form_target));
		break;
	case 2:
		std::cout << "Intern creates " << form_name << '\n';
		return (new PresidentialPardonForm(form_target));
		break;
	
	default:
		break;
	}
	return NULL;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */