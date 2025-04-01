/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:00:03 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/01 15:58:37 by sranaivo         ###   ########.fr       */
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
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	(void) rhs;
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, Intern const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


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
		std::cerr << "the provided form name does not exist" << '\n';
		return (NULL);
	}
	
	switch (form_type)
	{
	case 0:
		return (new ShrubberyCreationForm(form_target));
		break;
	case 1:
		return (new RobotomyRequestForm(form_target));
		break;
	case 2:
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