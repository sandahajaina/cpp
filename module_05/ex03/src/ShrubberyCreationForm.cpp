/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:34:54 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/10 12:46:36 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137, "default") {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : 
	AForm("shrubbery creation", 145, 137, src.getTarget()) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
	AForm("shrubbery creation", 145, 137, target) {}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() {}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	(void) rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!(getIsSigned()))
	{
		std::cout << "Error: form not signed" << '\n';
		return;
	}

	if (executor.getGrade() > getGradeRequiredToExecuteIt())
		throw GradeTooLowException("Error: the executor's grade is too low");
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (file.is_open())
	{
		file << TREES;
		file.close();
	}
	else throw "Error: Unable to open file";
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */