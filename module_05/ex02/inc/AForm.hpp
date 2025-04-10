/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:34:15 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/10 12:39:20 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#define TREES "\
        _-_           _-_        \n\
     /~~   ~~\\     /~~   ~~\\     \n\
  /~~         ~~ ~~         ~~\\\n\
 {     ~   ~     ~   ~    ~   }\n\
  \\  ~     ~  ~     ~     ~  / \n\
   \\__~___~___~___~___~_____/  \n\
         ||         ||         \n\
         ||         ||         \n"


# include <iostream>
# include <string>
# include <exception>
#include <iostream>
#include <fstream>
# include "Bureaucrat.hpp"

class AForm
{

	public:

		AForm();
		AForm( AForm const & src );
		AForm(std::string name, int sign_grade, int execute_grade, std::string target);
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int			getGradeRequiredToSignIt() const;
		int			getGradeRequiredToExecuteIt() const;

		void beSigned(Bureaucrat& b);

		virtual void execute(Bureaucrat const & executor) const = 0;

		const std::string& getTarget() const;

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
		const std::string	_target;

		static const int _maxGrade;
		static const int _minGrade;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ FORM_H */