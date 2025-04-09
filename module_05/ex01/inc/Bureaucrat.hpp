/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:24:44 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 16:59:54 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "MyException.hpp"

class Form;

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat( const std::string& name, int grade);
		~Bureaucrat();

		//overloads
		Bureaucrat &		operator=( Bureaucrat const & rhs );

		// accessors
		const std::string& getName() const;
		int	getGrade() const;

		// methods
		void incrementGrade();
		void decrementGrade();
		void signForm(Form& form);

		class GradeTooHighException : public MyException
		{
			public:
				GradeTooHighException(const char* msg);
		};

		class GradeTooLowException : public MyException
		{
			public:
				GradeTooLowException(const char *msg);
		};

	private:
		const std::string	_name;
		int					_grade;
		static int			_maxGrade;
		static int			_minGrade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */