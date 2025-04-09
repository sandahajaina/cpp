/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:34:15 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 17:07:45 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{

	public:

		Form();
		Form( Form const & src );
		Form(std::string name, int sign_grade, int execute_grade);
		~Form();

		Form &		operator=( Form const & rhs );

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int			getGradeRequiredToSignIt() const;
		int			getGradeRequiredToExecuteIt() const;

		void beSigned(Bureaucrat& b);

		class GradeTooHighException : public MyException
		{
			public:
				GradeTooHighException(const char* msg);
		};

		class GradeTooLowException : public MyException
		{
			public:
				GradeTooLowException(const char* msg);
		};

	private:
		const std::string	_name;
		bool 				_is_signed;
		const int			_grade_required_to_sign_it;
		const int			_grade_required_to_execute_it;

		static const int _maxGrade;
		static const int _minGrade;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */