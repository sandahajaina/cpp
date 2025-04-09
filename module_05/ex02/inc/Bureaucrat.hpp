/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sranaivo <sranaivo@student.42antananarivo. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:24:44 by sranaivo          #+#    #+#             */
/*   Updated: 2025/04/09 22:27:59 by sranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "MyException.hpp"

class AForm;

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		const std::string& getName() const;
		int	getGrade() const;

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm& form);
		void executeForm(AForm const& form) const;

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