/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:34:15 by sranaivo          #+#    #+#             */
/*   Updated: 2025/03/31 16:01:45 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class AForm
{

	public:

		AForm();
		AForm( AForm const & src );
		AForm(std::string name, int sign_grade, int execute_grade);
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int			getGradeRequiredToSignIt() const;
		int			getGradeRequiredToExecuteIt() const;

		void beSigned(Bureaucrat& b);

		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		bool 				_is_signed;
		const int			_grade_required_to_sign_it;
		const int			_grade_required_to_execute_it;

		static const int _maxGrade;
		static const int _minGrade;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ FORM_H */