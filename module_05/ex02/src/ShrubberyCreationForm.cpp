/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:34:54 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 23:16:36 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : 
	AForm("shrubbery creation", 145, 137), _target(src.getTarget()) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
	AForm("shrubbery creation", 145, 137) ,_target(target) {}


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
		std::cout << "error: form not signed" << '\n';
		return;
	}
	try
	{
		if (executor.getGrade() > getGradeRequiredToExecuteIt())
			throw GradeTooLowException("Error: the executor's grade is too low");

		std::string filename = _target + "_shrubbery";
		std::ofstream file;
		file.open(filename.c_str());
		file << TREES;
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& ShrubberyCreationForm::getTarget() const {return _target;}


/* ************************************************************************** */