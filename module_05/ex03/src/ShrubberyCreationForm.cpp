/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:34:54 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/01 14:51:01 by sranaivo         ###   ########.fr       */
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

// std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!(getIsSigned()))
	{
		std::cerr << "error: form not signed" << '\n';
		return;
	}
	if (executor.getGrade() > getGradeRequiredToExecuteIt())
		throw GradeTooLowException();
	else
	{
		std::string filename = _target + "_shrubbery";
		std::ofstream file;
		file.open(filename.c_str());
		file << TREES;
		file.close();
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& ShrubberyCreationForm::getTarget() const {return _target;}


/* ************************************************************************** */